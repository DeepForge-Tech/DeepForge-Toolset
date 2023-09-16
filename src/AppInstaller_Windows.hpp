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
// Importing Libraries
#ifndef APPINSTALLER_WINDOWS_HPP_
#define APPINSTALLER_WINDOWS_HPP_
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <filesystem>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "Progressbar.hpp"
#include <cctype>
#include <fstream>
#include <functional>
#include "Logger.cpp"
#include "json/json.h"
#include <time.h>
#include <stdint.h>
#include <chrono>
#include "DatabaseConnect.cpp"
#include "fmt/format.h"

// Checking the name of the operating system and importing the necessary libraries for this system
#if defined(__linux__)
// cout << "Linux" << endl;
#elif __FreeBSD__
// cout << "FreeBSD" << endl;
#elif __APPLE__
// cout << "macOS" << endl;
#elif _WIN32
    #include <conio.h>
    #include <Windows.h>
    #include <tchar.h>
    #include <shlwapi.h>
    #pragma comment(lib, "shlwapi.lib")
    #include "shlobj.h"
#endif

using namespace std;
using namespace Json;
using namespace Logger;
using namespace DB;
using namespace Bar;

// Variables
// int type
int Percentage;
int TempPercentage;
int result;
int output_func;
// float type 
float LastDownloadSpeed;
float LastSize;
float LastTotalSize;
// double type
double DownloadSpeed = 0.0;
// init classes
MainLogger logger(true, "logs/DeepForgeToolset.log");
ProgressBar_v1 progressbar;
Value translate;
CURL *curl = curl_easy_init();
CURLcode res;
// map type
map<string, string> Packages;
map<string, string> DevelopmentPacks;
map<int, string> Languages{
    {1, "Python"}, {2, "JavaScript"}, {3, "C++"}, {4, "Java"}, {5, "Go"}, {6, "Rust"}, {7, "Ruby"}, {8, "C"}, {9, "C#"}, {10, "PHP"}, {11, "Kotlin"}};

string replaceAll(string str, const string &from, const string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
// string type
const string TrueVarious[3] = {"yes", "y", "1"};
string Architecture;
string ProjectDir = std::filesystem::current_path().generic_string();
string haveString = "";
string new_sentence;
string LangReadySet;
// Get user folder(example - C:\Users\NameUser)
char *UserFolder = getenv("USERPROFILE");
string DesktopPath = string(UserFolder) + "\\Desktop";
string InstallDelimiter = "========================================================";
string ApplicationDir = "C:\\ProgramData\\DeepForge\\DeepForge-Toolset";
string DatabasePath = replaceAll(ProjectDir, "/", "\\") == DesktopPath ? ApplicationDir + "\\DB\\AppInstaller.db" : ProjectDir + "\\DB\\AppInstaller.db";
Database database;

// Function for update information from database about packages and development packs
void UpdateData()
{
    try
    {
        /* This code block checks if the database file specified by `DatabasePath` exists. 
        If the file does not exist, it proceeds to download the file from a specified URL using the libcurl library. */
        if (filesystem::exists(DatabasePath) == false)
        {
            string url = "https://github.com/DeepForge-Technology/DeepForge-Toolset/releases/download/v0.1_win_amd64/AppInstaller.db";
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
            curl_easy_cleanup(curl);
            fclose(file);
        }
        database.open(&DatabasePath);
        Packages = database.GetAllValuesFromDB("Applications", "Windows");
        DevelopmentPacks = database.GetDevPackFromDB("DevelopmentPacks", "Language");
    }
    catch(exception& error)
    {
        cout << error.what() << endl;
        logger.Error("❌ An error occurred when trying to download the database and open it");
    }
}

#endif