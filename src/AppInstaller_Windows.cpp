/*  The MIT License (MIT)
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
#define FMT_HEADER_ONLY
#include "AppInstaller_Windows.hpp"

namespace Windows
{
    /**
     * The function `CallbackProgress` is a callback function used to track the progress of a download
     * and update a progress bar accordingly.
     *
     * @param ptr The `ptr` parameter is a pointer to user-defined data that can be passed to the
     * callback function. It allows you to pass additional information or context to the callback
     * function if needed.
     * @param TotalToDownload The total size of the file to be downloaded in bytes.
     * @param NowDownloaded The amount of data that has been downloaded so far.
     * @param TotalToUpload The total size of the data to be uploaded in bytes.
     * @param NowUploaded The parameter "NowUploaded" represents the amount of data that has been
     * uploaded so far. It is a double data type.
     *
     * @return an integer value of 0.
     */
    int CallbackProgress(void *ptr, double TotalToDownload, double NowDownloaded, double TotalToUpload, double NowUploaded)
    {
        if (TotalToDownload <= 0.0)
        {
            return 0;
        }
        // double DownloadSpeed;
        Percentage = static_cast<float>(NowDownloaded) / static_cast<float>(TotalToDownload) * 100;
        /* The bellow code is checking if the `TempPercentage` is not equal to `Percentage` and is less
        than or equal to 100. If this condition is true, it retrieves the download speed using
        `curl_easy_getinfo` and updates a progress bar using the `progressbar.Update` function. It
        also updates some variables (`LastDownloadSpeed`, `LastSize`, `LastTotalSize`, and
        `TempPercentage`) with the current values. */
        if (TempPercentage != Percentage && TempPercentage <= 100)
        {
            progressbar.Update(NowDownloaded, TotalToDownload);
            LastSize = NowDownloaded;
            LastTotalSize = TotalToDownload;
            TempPercentage = Percentage;
        }
        return 0;
    }
    /**
     * The function "WriteData" writes data from a pointer to a file stream.
     *
     * @param ptr ptr is a pointer to the data that needs to be written to the file. It points to the
     * starting address of the data.
     * @param size The size parameter specifies the size of each element to be written.
     * @param nmemb The parameter "nmemb" stands for "number of members". It represents the number of
     * elements, each with a size of "size", that you want to write to the file.
     * @param stream The stream parameter is a pointer to a FILE object, which represents the file
     * stream that the data will be written to.
     *
     * @return the number of elements successfully written to the file stream.
     */
    size_t WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream)
    {
        size_t WriteProcess = fwrite(ptr, size, nmemb, stream);
        return WriteProcess;
    }

    class AppInstaller
    {
    public:
        /**
         * The function `InstallMake` installs the Make utility by extracting it from a zip archive and
         * adding it to the specified directory.
         *
         * @return an integer value.
         */
        int InstallMake()
        {
            string NewMakeDir = database.GetValueFromDB("PackagesFromSource_Windows", "Make", "Directory");
            string ArchivePath = ProjectDir + "/utils/Make_3.81.zip ";
            string Command = "tar -xf" + ArchivePath + "--directory " + NewMakeDir;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewMakeDir;
            if (std::filesystem::exists(NewMakeDir) && std::filesystem::is_empty(NewMakeDir) == false)
            {
                cout << "✅ Make " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewMakeDir << endl;
                return 403;
            }
            /* The bellow code is checking if a directory named "NewMakeDir" exists using the
            std::filesystem::exists function. If the directory does not exist, it creates the
            directory using the std::filesystem::create_directory function. */
            if (std::filesystem::exists(NewMakeDir) == false)
            {
                std::filesystem::create_directory(NewMakeDir);
            }
            else if (std::filesystem::exists(NewMakeDir) && std::filesystem::is_empty(NewMakeDir) == true)
            {
                std::filesystem::remove_all(NewMakeDir);
                std::filesystem::create_directory(NewMakeDir);
            }
            result = system(Command.c_str());
            system(Command_AddPath.c_str());
            cout << "Make " << translate["Located"].asString() << " " << NewMakeDir << endl;
            return 0;
        }

        /**
         * The function `InstallVCpkg()` installs vcpkg package manager on Windows.
         *
         * @return an integer value. The possible return values are:
         * - 403: Indicates that vcpkg is already installed in the specified directory.
         * - 0: Indicates that vcpkg has been successfully installed and located in the specified
         * directory.
         */
        int InstallVCpkg()
        {
            string NewVCpkgDir = database.GetValueFromDB("PackagesFromSource_Windows", "vcpkg", "Directory");
            string VCpkgRepository = database.GetValueFromDB("PackagesFromSource_Windows", "vcpkg", "Url");
            string PathRepository = NewVCpkgDir + "vcpkg";
            if (std::filesystem::exists(PathRepository) && std::filesystem::is_empty(PathRepository) == false)
            {
                cout << "✅ vcpkg " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << PathRepository << endl;
                return 403;
            }
            string Command = "cd " + NewVCpkgDir + " && git clone " + VCpkgRepository;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewVCpkgDir + "vcpkg";
            string Command_Install = NewVCpkgDir + "vcpkg\\bootstrap-vcpkg.bat -disableMetrics";
            MainInstaller("Git");
            result = system(Command.c_str());
            if (result == 0)
            {
                system(Command_Install.c_str());
                system(Command_AddPath.c_str());
                cout << "vcpkg " << translate["Located"].asString() << " " << PathRepository << endl;
                return 0;
            }
            else
            {
                return -1;
            }
        }

        /**
         * The function `InstallPHP` installs PHP by extracting a zip archive to a specified directory
         * and adds the directory to the system's PATH.
         *
         * @return an integer value.
         */
        int InstallPHP()
        {
            string NewPHPDir = database.GetValueFromDB("PackagesFromSource_Windows", "PHP", "Directory");
            string ArchivePath = ProjectDir + "/utils/php-8.2.9.zip ";
            string Command = "tar -xf" + ArchivePath + "--directory " + NewPHPDir;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewPHPDir;
            if (std::filesystem::exists(NewPHPDir) && std::filesystem::is_empty(NewPHPDir) == false)
            {
                cout << "✅ PHP " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewPHPDir << endl;
                return 403;
            }
            if (std::filesystem::exists(NewPHPDir) == false)
            {
                std::filesystem::create_directory(NewPHPDir);
            }
            else if (std::filesystem::exists(NewPHPDir) == true && std::filesystem::is_empty(NewPHPDir) == true)
            {
                std::filesystem::remove_all(NewPHPDir);
                std::filesystem::create_directory(NewPHPDir);
            }
            result = system(Command.c_str());
            cout << "" << endl;
            system(Command_AddPath.c_str());
            cout << "PHP " << translate["Located"].asString() << " " << NewPHPDir << endl;
            return 0;
        }
        /**
         * The function `InstallEclipse` downloads and installs Eclipse IDE on Windows.
         *
         * @return an integer value.
         */
        int InstallEclipse()
        {
            string EclipseUrl = database.GetValueFromDB("PackagesFromSource_Windows", "Eclipse IDE", "Url");
            string NewEclipseDir = database.GetValueFromDB("PackagesFromSource_Windows", "Eclipse IDE", "Directory");
            string ArchiveDir = ProjectDir + "/Downloads";
            string ArchivePath = ArchiveDir + "/eclipse-java-2023-06-R-win32-x86_64.zip ";
            if (std::filesystem::exists("C:\\eclipse") && std::filesystem::is_empty("C:\\eclipse") == false)
            {
                cout << "✅ Eclipse IDE " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewEclipseDir << "eclipse" << endl;
                return 403;
            }
            if (std::filesystem::exists(ArchiveDir) == false)
            {
                std::filesystem::create_directory(ArchiveDir);
            }
            Download(EclipseUrl, ArchiveDir);
            string Command = "tar -xf" + ArchivePath + "--directory " + NewEclipseDir;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewEclipseDir + "eclipse";
            system(Command.c_str());
            system(Command_AddPath.c_str());
            std::filesystem::remove(ArchivePath);
            cout << "Eclipse " << translate["Located"].asString() << " " << NewEclipseDir << "eclipse" << endl;
            return 0;
        }

        /**
         * The function `InstallKotlin` installs the Kotlin programming language by downloading and
         * extracting the Kotlin compiler from a specified URL.
         *
         * @return an integer value.
         */
        int InstallKotlin()
        {
            string NewKotlinDir = database.GetValueFromDB("PackagesFromSource_Windows", "Kotlin", "Directory");
            string KotlinUrl = database.GetValueFromDB("PackagesFromSource_Windows", "Kotlin", "Url");
            string ArchiveDir = ProjectDir + "/Downloads";
            string ArchivePath = ArchiveDir + "/kotlin-compiler-1.8.22.zip ";
            if (std::filesystem::exists("C:\\kotlinc") && std::filesystem::is_empty("C:\\kotlinc") == false)
            {
                cout << "✅ Kotlin " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewKotlinDir << "kotlinc" << endl;
                return 403;
            }
            if (std::filesystem::exists(ArchiveDir) == false)
            {
                std::filesystem::create_directory(ArchiveDir);
            }
            Download(KotlinUrl, ArchiveDir);
            string Command = "tar -xf" + ArchivePath + "--directory " + NewKotlinDir;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewKotlinDir;
            system(Command.c_str());
            system(Command_AddPath.c_str());
            std::filesystem::remove(ArchivePath);
            cout << "Kotlin " << translate["Located"].asString() << " " << NewKotlinDir << endl;
            return 0;
        }

        /**
         * The function `InstallWget` installs the Wget package by downloading it from a specified URL
         * and adding it to the system's PATH.
         *
         * @return an integer value.
         */
        int InstallWget()
        {
            string NewWgetDir = database.GetValueFromDB("PackagesFromSource_Windows", "Wget", "Directory");
            string WgetUrl = database.GetValueFromDB("PackagesFromSource_Windows", "Wget", "Url");
            string ApplicationPath = NewWgetDir + "/wget.exe ";
            if (std::filesystem::exists(NewWgetDir) && std::filesystem::is_empty(NewWgetDir) == false)
            {
                cout << "✅ Wget " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewWgetDir << endl;
                return 403;
            }
            if (std::filesystem::exists(NewWgetDir) == false)
            {
                std::filesystem::create_directory(NewWgetDir);
            }
            else if (std::filesystem::exists(NewWgetDir) == true && std::filesystem::is_empty(NewWgetDir) == true)
            {
                std::filesystem::remove_all(NewWgetDir);
                std::filesystem::create_directory(NewWgetDir);
            }
            Download(WgetUrl, NewWgetDir);
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewWgetDir;
            system(Command_AddPath.c_str());
            cout << "Wget " << translate["Located"].asString() << " " << NewWgetDir << endl;
            return 0;
        }

        /**
         * The function `InstallNginx` installs Nginx by extracting a zip archive and adding the
         * installation path to the system's PATH variable.
         *
         * @return an integer value. The possible return values are:
         * - 403: Nginx is already installed in the specified directory.
         * - 0: Nginx is successfully installed and located in the specified directory.
         * - Throws a logic_error exception if the zip archive is not found.
         */
        int InstallNginx()
        {
            string NewNginxDir = database.GetValueFromDB("PackagesFromSource_Windows", "Nginx", "Directory");
            string ArchivePath = ProjectDir + "/utils/Nginx-1.25.1.zip ";
            string Command = "tar -xf" + ArchivePath + "--directory " + NewNginxDir;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewNginxDir + "Nginx-1.25.1";
            if (std::filesystem::exists("C:\\Nginx-1.25.1") && std::filesystem::is_empty("C:\\Nginx-1.25.1") == false)
            {
                cout << "✅ Nginx " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewNginxDir << "Nginx-1.25.1" << endl;
                return 403;
            }
            if (std::filesystem::exists(ArchivePath))
            {
                result = system(Command.c_str());
                system(Command_AddPath.c_str());
                cout << "Nginx " << translate["Located"].asString() << " " << NewNginxDir << "Nginx-1.25.1" << endl;
                return 0;
            }
            else
            {
                string ErrorText = translate["LOG_ZIP_ARCHIVE_NOT_FOUND"].asString();
                logger.WriteError(ErrorText);
                return -1;
            }
        }

        /**
         * The function `InstallRedis` installs Redis by downloading it from a specified URL,
         * extracting the archive, adding the installation directory to the system path, and returning
         * an appropriate status code.
         *
         * @return an integer value. The possible return values are:
         * - 403: Redis is already installed in the specified directory.
         * - 0: Redis installation is successful.
         * - Throws a domain_error exception with the message "Unable to connect" if the result is 500.
         */
        int InstallRedis()
        {
            string NewRedisDir = database.GetValueFromDB("PackagesFromSource_Windows", "Redis", "Directory");
            string RedisUrl = database.GetValueFromDB("PackagesFromSource_Windows", "Redis", "Url");
            string name = (RedisUrl.substr(RedisUrl.find_last_of("/")));
            string ArchiveDir = ProjectDir + "/Downloads";
            string ArchivePath = ArchiveDir + "/" + name + " ";
            if (std::filesystem::exists(NewRedisDir) && std::filesystem::is_empty(NewRedisDir) == false)
            {
                cout << "✅ Redis " << translate["AlreadyInstalled"].asString() << " " << translate["in"].asString() << " " << NewRedisDir << endl;
                return 403;
            }
            if (std::filesystem::exists(ArchiveDir) == false)
            {
                std::filesystem::create_directory(ArchiveDir);
            }
            Download(RedisUrl, ArchiveDir);
            if (std::filesystem::exists(NewRedisDir) == false)
            {
                std::filesystem::create_directory(NewRedisDir);
            }
            else if (std::filesystem::exists(NewRedisDir) && std::filesystem::is_empty(NewRedisDir) == true)
            {
                std::filesystem::remove_all(NewRedisDir);
                std::filesystem::create_directory(NewRedisDir);
            }
            string Command = "tar -xf" + ArchivePath + "--directory " + NewRedisDir;
            string Command_AddPath = ProjectDir + "/utils/pathman.exe add " + NewRedisDir;
            system(Command.c_str());
            system(Command_AddPath.c_str());
            std::filesystem::remove(ArchivePath);
            cout << "Redis " << translate["Located"].asString() << " " << NewRedisDir << endl;
            return 0;
        }

        /* The bellow code is defining two function pointer types: `AppInstaller_funct_t` and
        `map_funct_t`. `AppInstaller_funct_t` is a function pointer type that points to a member
        function of the `AppInstaller` class that takes no arguments and returns an `int`.
        `map_funct_t` is a function pointer type that points to a function that takes no arguments
        and returns `void`. */
        using AppInstaller_funct_t = int (AppInstaller::*)(void);
        using map_funct_t = void (*)(void);

        map<string, AppInstaller_funct_t> PackagesFromSource{
            {"Eclipse IDE", &AppInstaller::InstallEclipse},
            {"Kotlin", &AppInstaller::InstallKotlin},
            {"vcpkg", &AppInstaller::InstallVCpkg},
            {"PHP", &AppInstaller::InstallPHP},
            {"Make", &AppInstaller::InstallMake},
            {"Wget", &AppInstaller::InstallWget},
            {"Nginx", &AppInstaller::InstallNginx},
            {"Redis", &AppInstaller::InstallRedis}};

        /**
         * The MainInstaller function checks if an application requires manual installation or if it
         * can be installed automatically, and then installs it accordingly.
         *
         * @param Name The parameter "Name" is a string that represents the name of an application.
         *
         * @return an integer value.
         */
        int MainInstaller(string Name)
        {
            try
            {
                string Value = database.GetValueFromDB("Applications", Name, "Windows");
                if (Value != "ManualInstallation")
                {
                    result = system(Value.c_str());
                }
                else if (PackagesFromSource.find(Name) != PackagesFromSource.end())
                {
                    result = (this->*(PackagesFromSource[Name]))();
                }
                else
                {
                    string InstallCommand = database.GetValueFromDB("PackagesFromSource_Windows", Name, "Command");
                    if (InstallCommand != "Empty")
                        result = system(InstallCommand.c_str());
                }
                return result;
            }
            catch (exception &error)
            {
                cout << error.what() << endl;
            }
        }
        // Function for update information from database about packages and development packs
        void UpdateData()
        {
            try
            {
                database.open(&DatabasePath);
                Packages = database.GetAllValuesFromDB("Applications", "Windows");
                DevelopmentPacks = database.GetDevPackFromDB("DevelopmentPacks", "Language");
            }
            catch (exception &error)
            {
                logger.WriteError(translate["LOG_ERROR_DOWNLOAD_DATABASE"].asString());
                logger.WriteError(error.what());
            }
        }

        AppInstaller()
        {
            UpdateData();
            InstallWinGet();
            cout << InstallDelimiter << endl;
        }

        ~AppInstaller()
        {
        }

    private:
        /**
         * The function checks if WinGet is installed and installs it if necessary.
         */
        void InstallWinGet()
        {
            cout << "WinGet ";
            result = system("winget -v");
            if (result != 0)
            {
                cout << translate["Installing"].asString() << " "
                     << "winget"
                     << " ..." << endl;
                string Command = "powershell.exe " + ProjectDir + "/Scripts/InstallWinGet.ps1";
                system(Command.c_str());
                cout << "✅ "
                     << "winget"
                     << " " << translate["Installed"].asString() << endl;
            }
        }
        /* The 'MakeDirectory' function is used to create a directory (folder) in the file system.*/
        void MakeDirectory(string dir)
        {
            string currentDir;
            string fullPath = "";
            string delimiter = "\\";
            size_t pos = 0;
            while ((pos = dir.find(delimiter)) != string::npos)
            {
                currentDir = dir.substr(0, pos);
                if (fullPath != "")
                {
                    fullPath = fullPath + "\\" + currentDir;
                    if (filesystem::exists(fullPath) == false)
                    {
                        filesystem::create_directory(fullPath);
                    }
                }
                else
                {
                    fullPath = currentDir + "\\";
                }
                dir.erase(0, pos + delimiter.length());
            }
            if (fullPath != "")
            {
                fullPath = fullPath + "\\" + dir;
            }
            else
            {
                fullPath = dir + "\\";
            }
            if (filesystem::exists(fullPath) == false)
            {
                filesystem::create_directory(fullPath);
            }
        }

        void DownloadDatabase()
        {
            try
            {
                /* This code block checks if the database file specified by `DatabasePath` exists.
                If the file does not exist, it proceeds to download the file from a specified URL using the libcurl library. */
                if (filesystem::exists(DatabasePath) == false)
                {
                    string url = "https://github.com/DeepForge-Technology/DeepForge-Toolset/releases/download/InstallerUtils/AppInstaller.db";
                    string name = (url.substr(url.find_last_of("/")));
                    string filename = ProjectDir + "/" + name.replace(name.find("/"), 1, "");
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
                            logger.WriteError(translate["LOG_ERROR_CURLE_COULDNT_CONNECT"].asString());
                        case CURLE_COULDNT_RESOLVE_HOST:
                            logger.WriteError(translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_HOST"].asString());
                        case CURLE_COULDNT_RESOLVE_PROXY:
                            logger.WriteError(translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_PROXY"].asString());
                        case CURLE_UNSUPPORTED_PROTOCOL:
                            logger.WriteError(translate["LOG_ERROR_CURLE_UNSUPPORTED_PROTOCOL"].asString());
                        case CURLE_SSL_CONNECT_ERROR:
                            logger.WriteError(translate["LOG_ERROR_CURLE_SSL_CONNECT_ERROR"].asString());
                        }
                    }
                }
            }
            catch (exception &error)
            {
                logger.WriteError(translate["LOG_ERROR_DOWNLOAD_DATABASE"].asString());
                logger.WriteError(error.what());
            }
        }

        int Download(string url, string dir)
        {
            string name = (url.substr(url.find_last_of("/")));
            string filename = dir + "/" + name.replace(name.find("/"), 1, "");
            FILE *file = fopen(filename.c_str(), "wb");
            CURL *curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &CallbackProgress);
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
                    throw domain_error(translate["LOG_ERROR_CURLE_COULDNT_CONNECT"].asString());
                case CURLE_COULDNT_RESOLVE_HOST:
                    throw domain_error(translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_HOST"].asString());
                case CURLE_COULDNT_RESOLVE_PROXY:
                    throw domain_error(translate["LOG_ERROR_CURLE_COULDNT_RESOLVE_PROXY"].asString());
                case CURLE_UNSUPPORTED_PROTOCOL:
                    throw domain_error(translate["LOG_ERROR_CURLE_UNSUPPORTED_PROTOCOL"].asString());
                case CURLE_SSL_CONNECT_ERROR:
                    throw domain_error(translate["LOG_ERROR_CURLE_SSL_CONNECT_ERROR"].asString());
                }
            }
            // If the progress bar is not completely filled in, then paint over manually
            if (Process < 100 && Process != Percentage)
            {
                for (int i = (Process - 1); i < 99; i++)
                {
                    progressbar.Update(LastSize, LastTotalSize);
                }
            }
            // Reset all variables and preferences
            progressbar.ResetAll();
            Percentage = 0;
            TempPercentage = 0;
            return 200;
        }
    };
    // Function to create a string with two application names
    string NewString(string sentence)
    {
        string new_sentence = "";
        // If the string is empty, then the first application name is added.
        if (haveString == "")
        {
            haveString = sentence;
            return new_sentence;
        }
        else
        {
            // Formatting string with two columns
            /* If the string already contains the name of the application,
            then the second name of the application is added and the formatted string is returned */
            new_sentence = fmt::format("{:<40} {:<15}\n", haveString, sentence);
            haveString = "";
            return new_sentence;
        }
    }
    // Method of make string to lower
    string to_lower(string sentence)
    {
        string new_sentence = "";
        for (int i = 0; i < sentence.length(); i++)
        {
            char ch = sentence[i];
            // cout << ch << endl;
            ch = tolower(ch);
            new_sentence += ch;
        }
        return new_sentence;
    }
    // Function for check of answer
    bool CheckAnswer(string answer)
    {
        bool status;
        // string Answer = to_lower(answer);

        string Answer = answer;
        for (int i = 0; i < TrueVarious->size(); i++)
        {
            if (Answer == TrueVarious[i] || Answer.empty() || Answer == "\n" || Answer == "да" || Answer == "ДА" || Answer == "Да")
            {
                status = true;
                break;
            }
        }
        return status;
    }
    // Initialization class
    AppInstaller Installer;
    // Function for install of DevelopmentPack(ready pack for certain programming language
    void InstallDevelopmentPack(string n)
    {
        try
        {
            Installer.UpdateData();
            // Init variables
            auto DevelopmentPack = database.GetAllValuesFromDB(DevelopmentPacks[n], "Windows");
            map<int, string> EnumeratePackages;
            string NamePackage;
            string delimiter = ",";
            size_t pos = 0;
            string token;
            /* The bellow code is retrieving values from a database for a specific development pack on the
            Windows platform. It then iterates over the retrieved values and creates a map of enumerated
            packages. It also creates a string representation of each package with its corresponding
            index. The code then checks if the number of packages is even or odd and prints the string
            representation accordingly. */
            for (int i = 1; const auto &element : DevelopmentPack)
            {
                /* The bellow code is inserting packages into a map called EnumeratePackages, where the
                key is an integer and the value is a string. It then creates a string called
                NamePackage by concatenating the key and the package name. It then calls a function
                called NewString with NamePackage as an argument and assigns the result to
                getNewString. */
                EnumeratePackages.insert(pair<int, string>(i, element.first));
                NamePackage = to_string(i) + ". " + element.first;
                // Formatting output text
                string getNewString = NewString(NamePackage);
                if (DevelopmentPack.size() % 2 == 0)
                {
                    if (getNewString != "")
                    {
                        cout << getNewString << endl;
                    }
                }
                else
                {
                    if (getNewString != "")
                    {
                        cout << getNewString << endl;
                    }
                    if (i == DevelopmentPack.size())
                    {
                        cout << NamePackage << endl;
                        haveString = "";
                    }
                }
                i++;
            }
            cout << "" << endl;
            cout << translate["SelectingPackages"].asString();
            getline(cin, SelectPackages);
            /* The bellow code is splitting a string called `SelectPackages` into multiple tokens using a
            delimiter (","). It then checks if each token is present in a map called
            `EnumeratePackages`. If a token is found in the map, it retrieves the corresponding value
            (package name) and performs some installation-related operations. These operations include
            printing messages, calling a `MainInstaller` function with the package name, and logging
            success or error messages based on the output of the `MainInstaller` function. Finally, it
            removes the processed token from the `SelectPackages` string and continues the loop until
            all tokens */
            while ((pos = SelectPackages.find(delimiter)) != string::npos)
            {
                token = SelectPackages.substr(0, pos);
                if (EnumeratePackages.find(stoi(token)) != EnumeratePackages.end())
                {
                    NamePackage = EnumeratePackages[stoi(token)];
                    // =============================
                    cout << InstallDelimiter << endl;
                    cout << translate["Installing"].asString() << " " << NamePackage << " ..." << endl;
                    // Install application
                    output_func = Installer.MainInstaller(NamePackage);
                    // Loggin and print messages
                    if (output_func == 0)
                    {
                        string SuccessText = "==> ✅ " + NamePackage + " " + translate["Installed"].asString();
                        cout << SuccessText << endl;
                    }
                    else if (output_func != 403)
                    {
                        string ErrorText = "==> ❌ " + translate["ErrorInstall"].asString() + " " + NamePackage;
                        cerr << ErrorText << endl;
                    }
                    SelectPackages.erase(0, pos + delimiter.length());
                }
            }

            /* The bellow code is checking if a package with a specific ID exists in a map called
            EnumeratePackages. If the package exists, it retrieves the name of the package and proceeds
            to install it using the MainInstaller function from the Installer object. After
            installation, it logs and prints success or error messages based on the output of the
            installation process. */
            if (EnumeratePackages.find(stoi(SelectPackages)) != EnumeratePackages.end())
            {
                NamePackage = EnumeratePackages[stoi(SelectPackages)];
                // =============================
                cout << InstallDelimiter << endl;
                cout << translate["Installing"].asString() << " " << NamePackage << " ..." << endl;
                // Install application
                output_func = Installer.MainInstaller(NamePackage);
                // Logging and print messages
                if (output_func == 0)
                {
                    string SuccessText = "==> ✅ " + NamePackage + " " + translate["Installed"].asString();
                    cout << SuccessText << endl;
                }
                else if (output_func != 403)
                {
                    string ErrorText = "==> ❌ " + translate["ErrorInstall"].asString() + " " + NamePackage;
                    cerr << ErrorText << endl;
                }
            }
            cout << InstallDelimiter << endl;
        }
        catch (exception &error)
        {
            string ErrorText = "==> ❌ " + string(error.what());
            logger.WriteError(error.what());
            cerr << ErrorText << endl;
        }
    }
}