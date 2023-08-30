#include <filesystem>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#pragma comment(lib, "urlmon.lib")
#include "Progressbar.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../DatabaseConnect.cpp"
#include <map>

using namespace std;
using namespace DB;

namespace Windows
{
    int result;
    int Percentage;
    int TempPercentage = 0;
    string Architecture;
    float LastSize;
    float LastTotalSize;
    // const string DownloadURL = "https://github.com/JetBrains/kotlin/releases/download/v1.8.22/kotlin-compiler-1.8.22.zip";
    // const string InstallPath = "kotlin-compiler-1.8.22.zip";
    string Answer;
    const string NewApplicationFolder = "C:\\ProgramData\\DeepForge\\DeepForge-Toolset";
    const string NewTempFolder = NewApplicationFolder + "\\Temp";
    ProgressBar progressbar;
    const string DB_URL = "https://github.com/DeepForge-Technology/DeepForge-Toolset/releases/download/versions.db/Versions.db";
    std::filesystem::path ProjectDir = std::filesystem::current_path().generic_string();
    string DB_PATH = NewTempFolder + "\\Versions.db";
    string NameVersionTable = "WindowsVersions";
    
    class WriteData : public IBindStatusCallback
    {
    public:
        HRESULT __stdcall QueryInterface(const IID &, void **)
        {
            return E_NOINTERFACE;
        }
        ULONG STDMETHODCALLTYPE AddRef(void)
        {
            return 1;
        }
        ULONG STDMETHODCALLTYPE Release(void)
        {
            return 1;
        }
        HRESULT STDMETHODCALLTYPE OnStartBinding(DWORD dwReserved, IBinding *pib)
        {
            return E_NOTIMPL;
        }
        virtual HRESULT STDMETHODCALLTYPE GetPriority(LONG *pnPriority)
        {
            return E_NOTIMPL;
        }
        virtual HRESULT STDMETHODCALLTYPE OnLowResource(DWORD reserved)
        {
            return S_OK;
        }
        virtual HRESULT STDMETHODCALLTYPE OnStopBinding(HRESULT hresult, LPCWSTR szError)
        {
            return E_NOTIMPL;
        }
        virtual HRESULT STDMETHODCALLTYPE GetBindInfo(DWORD *grfBINDF, BINDINFO *pbindinfo)
        {
            return E_NOTIMPL;
        }
        virtual HRESULT STDMETHODCALLTYPE OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC *pformatetc, STGMEDIUM *pstgmed)
        {
            return E_NOTIMPL;
        }
        virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(REFIID riid, IUnknown *punk)
        {
            return E_NOTIMPL;
        }

        virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
        {

            Percentage = static_cast<float>(ulProgress) / static_cast<float>(ulProgressMax) * 100;
            if (TempPercentage != Percentage && TempPercentage <= 98)
            {
                progressbar.Update(0.0,(float)(ulProgress),(float)(ulProgressMax));
                LastSize = (float)(ulProgress);
                LastTotalSize = (float)(ulProgressMax);
                TempPercentage = Percentage;
            }
            return S_OK;
        }
    };
    // Main class
    class Installer
    {
    public:
        Installer()
        {
            // Changing the encoding in the Windows console
            system("chcp 65001");
            GetArchitectureOS();
        }
        void InstallDeepForgeToolset(string channel);
    private:
        int Download(string url, string dir)
        {
            try
            {
                WriteData writer;
                string name = (url.substr(url.find_last_of("/")));
                string filename = dir + "/" + name.replace(name.find("/"), 1, "");
                HRESULT Download = URLDownloadToFile(NULL, url.c_str(), filename.c_str(), 0, static_cast<IBindStatusCallback *>(&writer));
                if (Process < 100)
                {
                    for (int i = (Process - 1);i < 99;i++)
                    {
                        progressbar.Update(0.0,LastSize,LastTotalSize);
                    }
                }
                cout << "" << endl;
                return 200;
            }
            catch (exception error)
            {
                return 502;
            }
        }

        // string GetUserFolder()
        // {
            
        //     return to_string(*user);
        // }

        void CreateSymlink(string nameSymlink,string filePath)
        {
            // char *user = getenv("USER");
            string symlinkPath = "C:\\Users\\blackflame576\\Desktop\\" + nameSymlink;
            cout << symlinkPath << endl;
            CreateHardLinkA(symlinkPath.c_str(),filePath.c_str(),NULL);
        }

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
            fullPath = fullPath + "\\" + dir;
            if (filesystem::exists(fullPath) == false)
            {
                filesystem::create_directory(fullPath);
            }
        }
        // Method for getting architecture of OS
        void GetArchitectureOS() {
            #if defined(__x86_64__)
                Architecture = "amd64";
            #elif __arm__
                Architecture = "arm64";
            #endif
        }
    };
}