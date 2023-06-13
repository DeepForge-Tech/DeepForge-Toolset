// Импортирование необходимых библиотек
#include <curl/curl.h>
#include <iostream>
#include <cstdio>
#include <string>
#include "AppInstaller.h"
#include <map>
#include "Logger.h"

// Проверка названия операционной системы и импортрование нужных библиотек для этой системы
#if defined(__linux__)
    // cout << "Linux" << endl;
#elif __FreeBSD__
    // cout << "FreeBSD" << endl;
#elif __APPLE__
    // cout << "macOS" << endl;
#elif _WIN32
    #include <Windows.h>
#endif

using namespace std;
using funct_t = void(*)(void);
using namespace AppInstaller;
using namespace Logger;

// Переменные 
bool Install;
string LangReadySet;
string Answer;
string new_sentence;

size_t WriteData(void* ptr,size_t size,size_t nmemb,FILE* stream) {
    size_t WriteProcess = fwrite(ptr,size,nmemb,stream);
    return WriteProcess;
}

// Функции
// string to_lower(string sentence) {
//     new_sentence = "";
//     for (int i = 0;i<sizeof(sentence);i++) {
//         new_sentence += tolower(sentence[i]);
//     }
//     return new_sentence;
// }

class Main {
    public:
        // void Download(string url,auto filename) {
        //     cout << typeid(url).name() << endl;
        //     CURL* curl = curl_easy_init();
        //     FILE* file = fopen(filename,"wb");
        //     curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
        //     curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteData);
        //     curl_easy_setopt(curl,CURLOPT_WRITEDATA,file);
        //     CURLcode response = curl_easy_perform(curl);
        //     curl_easy_cleanup(curl);
        // }
        void CommandManager() {
            string InstallTools;
            cout << "1. Choose a ready-made set of DevelopmentTools for a specific programming language" << endl;
            cout << "2. Manual selection of DeveloperTools packages" << endl;
            cout << "3. Install all packages of DeveloperTools" << endl;
            cout << "Select the option to install DeveloperTools (Default - 2):";
            getline(cin,InstallTools);
            if (InstallTools == "1") {
                ReadySet();
            }
            else if (InstallTools == "2" or InstallTools.empty()) {
                ManualSelection();
            }
            else if (InstallTools == "3") {
                InstallAllPackages();
            }
            else {
                ManualSelection();
            }

        }
        void ManualSelection() {
            TypeInstall = "open";
            for (const auto &element:Packages) {
                // cout << p.first << "\t" << p.second << endl;
                string name = element.first;
                cout << name << endl;
                element.second();
            }
        }
        void ReadySet() {
            cout << "1. Python" << endl;
            cout << "2. JavaScript" << endl;
            cout << "3. C++" << endl;
            cout << "4. Java" << endl;
            cout << "5. Go" << endl;
            cout << "6. Rust" << endl;
            cout << "7. Ruby" << endl;
            cout << "8. C" << endl;
            cout << "9. C#" << endl;
            cout << "10. PHP" << endl;
            getline(cin,LangReadySet);
            if (LangReadySet == "1") {
                TypeInstall = "open";
                AppInstaller::PythonDevelopment();
            }
            else if (LangReadySet == "2") {
                TypeInstall = "open";
                AppInstaller::JavaDevelopment();
            }
            else if (LangReadySet == "3") {
                TypeInstall = "open";
                AppInstaller::CppDevelopment();
            }
            else if (LangReadySet == "4") {
                TypeInstall = "open";
                AppInstaller::JavaDevelopment();
            }
            else if (LangReadySet == "5") {
                TypeInstall = "open";
                AppInstaller::GoDevelopment();
            }
            else if (LangReadySet == "6") {
                TypeInstall = "open";
                AppInstaller::RustDevelopment();
            }
            else if (LangReadySet == "7") {
                TypeInstall = "open";
                AppInstaller::RubyDevelopment();
            }
            else if (LangReadySet == "8") {
                TypeInstall = "open";
                AppInstaller::CDevelopment();
            }
            else if (LangReadySet == "9") {
                TypeInstall = "open";
                AppInstaller::CSDevelopment();
            }
            else if (LangReadySet == "10") {
                TypeInstall = "open";
                AppInstaller::PHPDevelopment();
            }
        }
        void InstallAllPackages() {
            TypeInstall = "hidden";
            for (const auto &element:Packages) {
                string name = element.first;
                cout << name << endl;
                element.second();
            }
        }
        Main () {
            if (OS_NAME == "Windows") {
                InstallWinGet();
            }
            else if (OS_NAME == "macOS") {
                InstallBrew();
            }
            else if (OS_NAME == "Linux") {

            }
        }
        ~Main () {
            
        };
    private:
        void InstallBrew() {
            system("bash ./Scripts/InstallBrew.sh");
        }
        
        void InstallWinGet() {
            // system();
        }
    // Main::Main();
    // Main::~Main();
        
};

int main() {
    setlocale(LC_ALL, "Russian");
    setlocale(LC_CTYPE,"Russian");
    #if defined(__linux__)
        OS_NAME = "Linux";
    #elif __FreeBSD__
        OS_NAME = "FreeBSD";
    #elif __APPLE__
        OS_NAME = "macOS";
    #elif _WIN32
        OS_NAME = "Windows";
    #endif
    
    Main main;
    main.CommandManager();
    // string url;
    // cin >> url;
    // main.Download(url,"file.exe");
    system("pause");
    return 0;
}