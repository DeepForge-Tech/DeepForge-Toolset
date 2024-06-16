/*  GNU GENERAL PUBLIC LICENSE
    ============================================================================

    ██████╗ ███████╗███████╗██████╗ ███████╗ ██████╗ ██████╗  ██████╗ ███████╗
    ██╔══██╗██╔════╝██╔════╝██╔══██╗██╔════╝██╔═══██╗██╔══██╗██╔════╝ ██╔════╝
    ██║  ██║█████╗  █████╗  ██████╔╝█████╗  ██║   ██║██████╔╝██║  ███╗█████╗
    ██║  ██║██╔══╝  ██╔══╝  ██╔═══╝ ██╔══╝  ██║   ██║██╔══██╗██║   ██║██╔══╝
    ██████╔╝███████╗███████╗██║     ██║     ╚██████╔╝██║  ██║╚██████╔╝███████╗
    ╚═════╝ ╚══════╝╚══════╝╚═╝     ╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚══════╝

    ████████╗ ██████╗  ██████╗ ██╗     ███████╗███████╗████████╗
    ╚══██╔══╝██╔═══██╗██╔═══██╗██║     ██╔════╝██╔════╝╚══██╔══╝
       ██║   ██║   ██║██║   ██║██║     ███████╗█████╗     ██║
       ██║   ██║   ██║██║   ██║██║     ╚════██║██╔══╝     ██║
       ██║   ╚██████╔╝╚██████╔╝███████╗███████║███████╗   ██║
       ╚═╝    ╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚══════╝   ╚═╝

    ============================================================================
    Copyright (c) 2023 DeepForge Technology
    ============================================================================
    Organization: DeepForge Technology
    ============================================================================
    Author: Blackflame576
    ============================================================================
    Created: 4 Juny 2023
    ============================================================================
*/
#include <DeepForge-Toolset/Linux.hpp>

int Linux::Installer::UnpackArchive(std::string path_from, std::string path_to)
{
    try
    {
        if (!std::filesystem::exists(path_from))
        {
            throw std::runtime_error(fmt::format("UnpackArchive. {}", translate["LOG_ZIP_ARCHIVE_NOT_FOUND"].asString()));
        }

        std::string output_path;
        this->MakeDirectory(path_to);

        mz_zip_archive zip_archive;
        memset(&zip_archive, 0, sizeof(zip_archive));

        mz_zip_reader_init_file(&zip_archive, path_from.c_str(), 0);

        for (int i = 0; i < mz_zip_reader_get_num_files(&zip_archive); i++)
        {
            mz_zip_archive_file_stat file_stat;
            mz_zip_reader_file_stat(&zip_archive, i, &file_stat);

            output_path = path_to + "/" + file_stat.m_filename;
            std::filesystem::path path(output_path);
            std::filesystem::create_directories(path.parent_path());
            if (endsWith(output_path, "/"))
            {
                MakeDirectory(output_path);
            }
            else
            {
                std::ofstream out(output_path, std::ios::binary);
                if (!out)
                {
                    throw std::runtime_error(fmt::format("UnpackArchive. {} {}", translate["LOG_ERROR_CREATE_FILE"].asString(), output_path));
                }
                size_t fileSize = file_stat.m_uncomp_size;
                void *fileData = mz_zip_reader_extract_to_heap(&zip_archive, file_stat.m_file_index, &fileSize, 0);
                if (!fileData)
                {
                    throw std::runtime_error(fmt::format("UnpackArchive. {} {}", translate["LOG_ERROR_CREATE_FILE"].asString(), output_path));
                }

                out.write(static_cast<const char *>(fileData), fileSize);
                mz_free(fileData);

                out.close();
            }
        }

        mz_zip_reader_end(&zip_archive);
        return SUCCESS_STATUS_CODE;
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("UnpackArchive.{}", error.what()));
    }
}

int Linux::Installer::InstallDevelopmentPack(std::string LanguageTable)
{
    try
    {
        this->UpdateData();
        // Init variables
        DB::DatabaseValues DevelopmentPack;
        DB::EnumColDatabaseValues EnumeratePackages;
        std::string SelectedPackages;
        DevelopmentPack = database.GetTwoColumnsFromTable(LanguageTable, "Name", fmt::format("Linux_{}",Architecture), std::nullopt);
        EnumeratePackages = Enumerate<EnumStringHashMap>(DevelopmentPack);
        PrintFormatted(EnumeratePackages, EnumeratePackages.size());

        std::cout << "" << std::endl;
        std::cout << translate["SelectingPackages"].asString();
        std::getline(std::cin, SelectedPackages);

        InstallIfFound(SelectedPackages, EnumeratePackages, MainInstallerLink);
        return SUCCESS_STATUS_CODE;
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("InstallDevelopmentPack.", error.what()));
    }
}

std::string Linux::Installer::GetNameDistribution()
{
    std::ifstream stream("/etc/os-release");
    std::string line;
    std::regex nameRegex("^NAME=\"(.*?)\"$");
    std::smatch match;
    std::string name;
    while (std::getline(stream, line))
    {
        if (std::regex_search(line, match, nameRegex))
        {
            name = match[1].str();
            break;
        }
    }
    return name;
}

int Linux::Installer::UpdateData()
{
    try
    {
        DB::DatabaseValues parameters;
        database.open(&DatabasePath);
        Languages = database.GetArrayOneColumnFromTable("DevelopmentPacks", "Language", std::nullopt);
        Packages = database.GetTwoColumnsFromTable("Applications", "Name", fmt::format("Linux_{}",Architecture), std::nullopt);
        NameDistribution = GetNameDistribution();
        DevelopmentPacks = database.GetArrayOneColumnFromTable("DevelopmentPacks", "Language", std::nullopt);
        parameters = {{"Name", NameDistribution}};
        PackageManager = database.GetValueFromRow("SupportedOS", "PackageManager", parameters);
        return SUCCESS_STATUS_CODE;
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("UpdateData.{}{}", error.what(), fmt::format("{} {}", translate["LOG_ERROR_UPDATE_LIST_PACKAGES"].asString(), std::string(error.what()))));
    }
}

int Linux::Installer::MainInstaller(std::string Name)
{
    try
    {
        int result = 0;
        std::string Value;
        std::string InstallCommand;
        DB::DatabaseValues parameters;

        parameters = {{"Name", Name}};
        Value = database.GetValueFromRow("Applications", fmt::format("Linux_{}",Architecture), parameters);

        std::cout << InstallDelimiter << std::endl;

        if (Value != "ManualInstallation" && Value != "Not Found")
        {
            std::cout << fmt::format("{} {}...", translate["Installing"].asString(), Name) << std::endl;
            result = system(Value.c_str());
        }
        else
        {
            // Get command from database for manual installation package.
            InstallCommand = database.GetValueFromRow(fmt::format("PackagesFromSource_Linux_{}",Architecture), PackageManager, parameters);
            switch (hashString(InstallCommand.c_str()))
            {
            case hashString("Empty"):
                result = this->InstallPackages(Name, InstallCommand);
                break;
            default:
                result = system(InstallCommand.c_str());
                break;
            }
        }
        // Check status code of installation process.
        switch (result)
        {
        case SUCCESS_STATUS_CODE:
            std::cout << fmt::format("==> ✅ {} {}", Name, translate["Installed"].asString()) << std::endl;
            break;
        case FAILED_STATUS_CODE:
            throw std::runtime_error(fmt::format("MainInstaller.{} {}", translate["ErrorInstall"].asString(), Name));
            break;
        }
        return result;
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("MainInstaller.{}", error.what()));
    }
}

int Linux::Installer::InstallSnap()
{
    try
    {
        int result;
        DB::DatabaseValues parameters;
        std::string InstallCommand;
        UpdateData();
        result = system("snap --version");
        if (result == 0)
        {
            system("sudo ln -s /var/lib/snapd/snap /snap > /dev/null");
            system("sudo systemctl restart snapd.service > /dev/null");
        }
        else
        {
            parameters = {{"Name","snap"}};
#if defined(__x86_64__)
            InstallCommand = database.GetValueFromRow("PackagesFromSource_Linux_amd64", PackageManager, parameters);
#elif __arm__ || __aarch64__ || _M_ARM64
            InstallCommand = database.GetValueFromRow("PackagesFromSource_Linux_arm64", PackageManager, parameters);
#endif
        result = system(InstallCommand.c_str());
        }
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("InstallSnap.{}", error.what()));
    }
}

int Linux::Installer::DownloadDatabase()
{
    try
    {
        /* This code block checks if the database file specified by `DatabasePath` exists.
        If the file does not exist, it proceeds to download the file from a specified URL using the libcurl library. */
        if (std::filesystem::exists(DatabasePath) == false)
        {
            std::string url = "https://github.com/DeepForge-Technology/DeepForge-Toolset/releases/download/InstallerUtils/AppInstaller.db";
            std::string name = (url.substr(url.find_last_of("/")));
            std::string filename = ProjectFolder + "/" + name.replace(name.find("/"), 1, "");
            FILE *file = fopen(filename.c_str(), "wb");
            CURL *curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_FILETIME, 1L);
            curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
            CURLcode response = curl_easy_perform(curl);
            /* `curl_easy_cleanup(curl);` is a function call to clean up and release resources associated with a CURL handle. It is used to free the resources allocated by `curl_easy_init()` function, which initializes a CURL handle for making HTTP requests. This function should be called after the request is completed or when the handle is no longer needed to avoid memory leaks. */
            curl_easy_cleanup(curl);
            fclose(file);
            /* This code block is checking the response from the libcurl library after performing an HTTP request. If the response is not CURLE_OK (indicating a successful request), it enters the switch statement to handle different error cases. Depending on the specific error code, it logs an appropriate error message using the logger object. */
            if (response != CURLE_OK)
            {
                switch (response)
                {
                case CURLE_COULDNT_CONNECT:
                    logger.writeLog("Error", translate["LOG_ERROR_CURLE_COULDNT_CONNECT"].asString());
                    break;
                case CURLE_COULDNT_RESOLVE_HOST:
                    logger.writeLog("Error", translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_HOST"].asString());
                    break;
                case CURLE_COULDNT_RESOLVE_PROXY:
                    logger.writeLog("Error", translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_PROXY"].asString());
                    break;
                case CURLE_UNSUPPORTED_PROTOCOL:
                    logger.writeLog("Error", translate["LOG_ERROR_CURLE_UNSUPPORTED_PROTOCOL"].asString());
                    break;
                case CURLE_SSL_CONNECT_ERROR:
                    logger.writeLog("Error", translate["LOG_ERROR_CURLE_SSL_CONNECT_ERROR"].asString());
                    break;
                }
            }
        }
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("DownloadDatabase.{}{}", translate["LOG_ERROR_DOWNLOAD_DATABASE"].asString(), std::string(error.what())));
    }
}

int Linux::Installer::Download(std::string url, std::string dir, bool Progress)
{
    try
    {
        withProgress = Progress;
        std::string name = (url.substr(url.find_last_of("/")));
        std::string filename = dir + "/" + name.replace(name.find("/"), 1, "");
        FILE *file = fopen(filename.c_str(), "wb");
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        if (Progress)
        {
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &CallbackProgress);
        }
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_FILETIME, 1L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        CURLcode response = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(file);
        /* The bellow code is checking the value of the variable "response" and performing
        different actions based on its value. If the value of "response" is not equal to
        CURLE_OK, it enters a switch statement. Inside the switch statement, it checks the
        value of "response" against different cases and performs specific actions for each
        case. The actions involve writing and logging different error messages based on the
        value of "response". */
        if (response != CURLE_OK)
        {
            switch (response)
            {
            case CURLE_COULDNT_CONNECT:
                throw std::domain_error(translate["LOG_ERROR_CURLE_COULDNT_CONNECT"].asString());
                break;
            case CURLE_COULDNT_RESOLVE_HOST:
                throw std::domain_error(translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_HOST"].asString());
                break;
            case CURLE_COULDNT_RESOLVE_PROXY:
                throw std::domain_error(translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_PROXY"].asString());
                break;
            case CURLE_UNSUPPORTED_PROTOCOL:
                throw std::domain_error(translate["LOG_ERROR_CURLE_UNSUPPORTED_PROTOCOL"].asString());
                break;
            case CURLE_SSL_CONNECT_ERROR:
                throw std::domain_error(translate["LOG_ERROR_CURLE_SSL_CONNECT_ERROR"].asString());
                break;
            }
        }
        if (Progress == true)
        {
            // If the progress bar is not completely filled in, then paint over manually
            for (int i = progressbar.progress; i < 100; i++)
            {
                progressbar.update(LastSize, LastTotalSize);
            }
            // Reset all variables and preferences
            progressbar.resetAll();
            Percentage = 0;
            TempPercentage = 0;
        }
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("Download.{}", std::string(error.what())));
    }
}

int Linux::Installer::MakeDirectory(std::string dir)
{
    try
    {
        std::string currentDir;
        std::string fullPath;
        std::string delimiter = ".";
        size_t pos = 0;
        while ((pos = dir.find(delimiter)) != std::string::npos)
        {
            currentDir = dir.substr(0, pos);
            if (!fullPath.empty())
            {
                fullPath = fullPath + "/" + currentDir;
                if (!std::filesystem::exists(fullPath))
                {
                    std::filesystem::create_directory(fullPath);
                }
            }
            else
            {
                fullPath = "/" + currentDir;
            }
            dir.erase(0, pos + delimiter.length());
        }
        fullPath = fullPath + "/" + dir;
        if (!std::filesystem::exists(fullPath))
        {
            std::filesystem::create_directory(fullPath);
        }
    }
    catch (std::exception &error)
    {
        throw std::runtime_error(fmt::format("MakeDirectory.{}", error.what()));
    }
}

int Linux::Installer::InstallPackages(const std::string &Name, const std::string &Command)
{
    try
    {
        DB::DatabaseValues parameters;
        std::string NewPackageFolder;
        std::string PackageUrl;
        std::string name;
        std::string ArchivePath;
        std::string Command_AddPath;

        parameters = {{"Name", Name}};
        NewPackageFolder = PackagesFolder + Name;
        #if defined(__x86_64__)
        PackageUrl = database.GetValueFromRow("PackagesFromSource_Linux_amd64", "Url", parameters);
        #elif __arm__ || __aarch64__ || _M_ARM64
        PackageUrl = database.GetValueFromRow("PackagesFromSource_Linux_arm64", "Url", parameters);
        #endif
        name = (PackageUrl.substr(PackageUrl.find_last_of("/")));
        ArchivePath = ArchivesFolder + "/" + name;
        Command_AddPath = ArchivesFolder + "/pathman add " + NewPackageFolder;

        if (std::filesystem::exists(NewPackageFolder) && !std::filesystem::is_empty(NewPackageFolder))
        {
            std::cout << fmt::format("✅ {} {} {} {}", Name, translate["AlreadyInstalled"].asString(), translate["in"].asString(), NewPackageFolder) << std::endl;
            return 403;
        }

        std::cout << fmt::format("{} {}...", translate["Installing"].asString(), Name) << std::endl;

        this->Download(PackageUrl, ArchivesFolder, true);
        if (!std::filesystem::exists(NewPackageFolder))
        {
            this->MakeDirectory(NewPackageFolder);
        }
        this->UnpackArchive(ArchivePath, NewPackageFolder);
        system(Command_AddPath.c_str());
        std::filesystem::remove(ArchivePath);
        std::cout << fmt::format("{} {} {}", Name, translate["Located"].asString(), NewPackageFolder) << std::endl;
        return SUCCESS_STATUS_CODE;
    }
    catch (std::exception &error)
    {
        throw std::domain_error(fmt::format("InstallPackages.{}", error.what()));
    }
}

bool Linux::Installer::CheckData()
{
    EnumStringHashMap sizes;
    std::string errorText;
    sizes = {
        {Languages ? 1 : 0,"Languages"},
        {Packages.size(),"Packages"},
        {DevelopmentPacks ? 1 : 0,"DevelopmentPacks"},
        {PackageManager.size(),"PackageManager"}
    };
    for (int i = 1;const auto &element : sizes)
    {
        if (element.first == 0)
        {
            errorText += fmt::format("{}) {}",i,element.second);
        }
    }
    if (errorText.size() != 0)
    {
        errorText += " is empty";
        throw std::runtime_error(errorText);
    }
}