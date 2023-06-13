#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;


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


namespace AppInstaller {
    using funct_t = void(*)(void);
    // Переменные
    bool Install;
    string OS_NAME;
    string Answer;
    string new_sentence;
    map<string,funct_t> Tools;
    const string TrueVarious[6] = {"yes","y","1","Да","ДА","да"};
    const string FalseVarious[6] = {"no","n","0","Нет","НЕТ","нет"};
    
    string TypeInstall = "open";
    // const string NameTools[100] = {};
    // #if defined(__linux__)
    //     OS_NAME = "Linux";
    // #elif __FreeBSD__
    //     OS_NAME = "FreeBSD";
    // #elif __APPLE__
    //     OS_NAME = "macOS";
    // #elif _WIN32
    //     OS_NAME = "Windows";
    // #endif

    // Функции
    string to_lower(string sentence) {
                new_sentence = "";
                for (int i = 0;i<sizeof(sentence);i++) {
                    new_sentence += tolower(sentence[i]);
                }
                return new_sentence;
    }

    bool CheckAnswer(string answer) {
                bool status;
                // string Answer = to_lower(answer);

                string Answer = answer;
                for (int i = 0;i < TrueVarious->size();i++) {
                    if (Answer == TrueVarious[i] || Answer.empty() || Answer == "\n") {
                        status = true;
                    }
                    else {
                        status = false;
                    }
                }
                return status;
    }
    void InstallGit() {
                if (TypeInstall == "open") {
                    cout << "Do you want to install Git?(default yes):";
                    // cin >> Answer;
                    getline(cin,Answer);
                    Install = CheckAnswer(Answer);
                    if (Install == true) {
                        if (OS_NAME == "Windows") {
                            system("winget install --id Git.Git -e --source winget");
                        }
                        else if (OS_NAME == "macOS") {
                            system("brew install --cask git");
                        }
                        else if (OS_NAME == "Linux") {

                        }
                    }
                }
                else if (TypeInstall == "hidden") {
                    if (OS_NAME == "Windows") {
                        system("winget install --id Git.Git -e --source winget");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask git");
                    }
                    else if (OS_NAME == "Linux") {

                    }
                }
    }
    void InstallVSCode() {
                cout << "Do you want to install VSCode?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if(OS_NAME == "Windows") {
                        system("winget install -e --id Microsoft.VisualStudioCode");
                    }
                    else if(OS_NAME == "macOS") {
                        system("brew install --cask visual-studio-code");
                    }
                }
    }
    void InstallWebStorm() {
                cout << "Do you want to install JetBrains WebStorm?(default yes)";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.WebStorm");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask webstorm");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallDocker() {
                cout << "Do you want to install Docker?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Docker.DockerDesktop");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask docker");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPostman() {
                cout << "Do you want to install Postman?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Postman.Postman");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask postman");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallRubyMine() {
                cout << "Do you want to install JetBrains RubyMine?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.RubyMine");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask rubymine");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallAqua() {
                cout << "Do you want to install JetBrains Aqua?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.Aqua.EAP");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallCLion() {
                cout << "Do you want to install JetBrains CLion?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.CLion");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask clion");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallDataGrip() {
                cout << "Do you want to install JetBrains DataGrip?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.DataGrip");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask datagrip");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallDataSpell() {
                cout << "Do you want to install JetBrains DataSpell?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.DataSpell");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask dataspell");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallFleet() {
                cout << "Do you want to install JetBrains Fleet?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.FleetLauncher.Preview");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask fleet");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallGoLand() {
                cout << "Do you want to install JetBrains GoLand?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.GoLand");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask goland");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallIntelliJCommunity() {
                cout << "Do you want to install JetBrains IntelliJIDEA Community?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.IntelliJIDEA.Community");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask intellij-idea-ce");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallIntelliJUltimate() {
                cout << "Do you want to install JetBrains IntelliJIDEA Ultimate?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.IntelliJIDEA.Ultimate");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask intellij-idea");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallReSharper() {
                cout << "Do you want to install JetBrains ReSharper?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.ReSharper");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallRider() {
                cout << "Do you want to install JetBrains Rider?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.Rider");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask rider");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPhpStorm() {
                cout << "Do you want to install JetBrains PHPStorm?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.PHPStorm");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask phpstorm");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstalldotUltimate() {
                cout << "Do you want to install JetBrains dotUltimate?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.dotUltimate");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallSpace() {
                cout << "Do you want to install JetBrains Space?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.Space");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask jetbrains-space");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallToolBox() {
                cout << "Do you want to install JetBrains Toolbox?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.Toolbox");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask jetbrains-toolbox");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPostgresql() {
                cout << "Do you want to install PostgreSQL?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id PostgreSQL.PostgreSQL");
                        system("winget install -e --id PostgreSQL.pgAdmin");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install postgresql@14");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallCLink() {
                cout << "Do you want to install Clink?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id chrisant996.Clink");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallNgrok() {
                cout << "Do you want to install Ngrok?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Ngrok.Ngrok");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask ngrok");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallWget() {
                cout << "Do you want to install Wget?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JernejSimoncic.Wget");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install wget");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallSublimeText() {
                cout << "Do you want to install SublimeText?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id SublimeHQ.SublimeText.4");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask sublime-text");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPyCharmCommunity() {
                cout << "Do you want to install PyCharm Community?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.PyCharm.Community");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask pycharm-ce");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPyCharmProffessional() {
                cout << "Do you want to install PyCharm Professional?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id JetBrains.PyCharm.Professional");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask pycharm");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPowerToys() {
                cout << "Do you want to install Microsoft PowerToys?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Microsoft.PowerToys");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallDiscord() {
                cout << "Do you want to install Discord?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Discord.Discord");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask discord");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallTelegram() {
                cout << "Do you want to install Telegram?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Telegram.TelegramDesktop");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask telegram");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallVNCServer() {
                cout << "Do you want to install RealVNC Server?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id RealVNC.VNCServer");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask vn-server");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallVNCViewer() {
                cout << "Do you want to install RealVNC Viewer?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id RealVNC.VNCViewer");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask vn-viewer");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallMongoDBCompass() {
                cout << "Do you want to install MongoDB Compass?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id MongoDB.Compass.Full");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask mongodb-compass");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallMongoDB() {
                cout << "Do you want to install MongoDB Server?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id MongoDB.Server");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install mongodb-community");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallMongoDBAtlas() {
                cout << "Do you want to install MongoDB MongoDBAtlasCLI?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id MongoDB.MongoDBAtlasCLI");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install mongodb-atlas-cli");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallNodeJS() {
                cout << "Do you want to install NodeJS?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id OpenJS.NodeJS");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install node");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallGoLang() {
                cout << "Do you want to install GoLang?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id GoLang.Go.1.18");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install go");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPython3_9() {
                cout << "Do you want to install Python 3.9?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Python.Python.3.9");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install python@3.9");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPython3_10() {
                cout << "Do you want to install Python 3.10?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Python.Python.3.10");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallPython3_11() {
                cout << "Do you want to install Python 3.11?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Python.Python.3.11");
                    }
                    else if (OS_NAME == "macOS") {
                        system("winget install -e --id Python.Python.3.11");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallJDK_19() {
                cout << "Do you want to install JDK 19?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Oracle.JDK.19");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install openjdk@19");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallJDK_18() {
                cout << "Do you want to install JDK 18?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Oracle.JDK.18");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install openjdk@18");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallRust() {
                cout << "Do you want to install Rust?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Rustlang.Rust.MSVC");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install rust");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallNetFramework() {
                cout << "Do you want to install Microsoft DotNet Framework?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Microsoft.DotNet.Framework.DeveloperPack_4");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install dotnet");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallRuby() {
                cout << "Do you want to install Ruby?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id RubyInstallerTeam.Ruby.3.1");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install ruby");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallMSYS2() {
                cout << "Do you want to install MSYS2?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id MSYS2.MSYS2");
                    }
                }
    }
    void InstallNuget() {
                cout << "Do you want to install Microsoft NuGet?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Microsoft.NuGet");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install nuget");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallGitHubDesktop() {
                cout << "Do you want to install GitHub Desktop?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id GitHub.GitHubDesktop");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install --cask github");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallGitHubCLi() {
                cout << "Do you want to install GitHub CLI?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id GitHub.cli");
                    }
                    else if (OS_NAME == "macOS") {

                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallKubernetes() {
                cout << "Do you want to install Kubernetes?(default yes):";
                getline(cin,Answer);
                Install = CheckAnswer(Answer);
                if (Install == true) {
                    if (OS_NAME == "Windows") {
                        system("winget install -e --id Kubernetes.kubectl");
                    }
                    else if (OS_NAME == "macOS") {
                        system("brew install kubernetes-cli");
                    }
                    else if (OS_NAME == "Linux") {
                        
                    }
                }
    }
    void InstallVisualStudioCommunity() {
        if (TypeInstall == "open") {
            cout << "Do you want to install Visual Studio Community?(default yes):";
            getline(cin,Answer);
            Install = CheckAnswer(Answer);
            if (Install == true) {
                if (OS_NAME == "Windows") {
                    system("winget install -e --id Microsoft.VisualStudio.2022.Community.Preview");
                }
                else if (OS_NAME == "macOS") {
                    system("brew install --cask visual-studio");
                }
                else if (OS_NAME == "Linux") {

                }
            }
        }
        else if (TypeInstall == "hidden") {

        }
    }

    void InstallVisualStudioProffessional() {
        if (TypeInstall == "open") {
            cout << "Do you want to install Visual Studio Proffessional?(default yes):";
            getline(cin,Answer);
            Install = CheckAnswer(Answer);
            if (Install == true) {
                if (OS_NAME == "Windows") {
                    system("winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview");
                }
                else if (OS_NAME == "macOS") {
                    system("brew install --cask visual-studio");
                }
                else if (OS_NAME == "Linux") {

                }
            }
        }
        else if (TypeInstall == "hidden") {
            
        }
    }

    map<string,funct_t> Packages {
        {"Git",InstallGit},{"VSCode",InstallVSCode},{"JetBrains WebStorm",InstallWebStorm},
        {"Docker",InstallDocker},{"Postman",InstallPostman},{"JetBrains RubyMine",InstallRubyMine},
        {"JetBrains Aqua",InstallAqua},{"JetBrains CLion",InstallCLion},{"JetBrains DataGrip",InstallDataGrip},
        {"JetBrains DataSpell",InstallDataSpell},{"JetBrains Fleet",InstallFleet},{"GoLand",InstallGoLand},
        {"JetBrains IntelliJ Community",InstallIntelliJCommunity},{"JetBrains IntelliJ Ultimate",InstallIntelliJUltimate},
        {"JetBrains ReSharper",InstallReSharper},{"JetBrains Rider",InstallRider},{"JetBrains PhpStorm",InstallPhpStorm},
        {"JetBrains dotUltimate",InstalldotUltimate},{"JetBrains Space",InstallSpace},{"JetBrains ToolBox",InstallToolBox},
        {"Postgresql",InstallPostgresql},{"Clink",InstallCLink},{"Ngrok",InstallNgrok},{"Wget",InstallWget},
        {"Sublime Text",InstallSublimeText},{"PyCharm Community",InstallPyCharmCommunity},{"PyCharm Proffessional",InstallPyCharmProffessional},
        {"Microsoft PowerToys",InstallPowerToys},{"Discord",InstallDiscord},{"Telegram",InstallTelegram},
        {"VNC Server",InstallVNCServer},{"VNC Viewer",InstallVNCViewer},{"MongoDB Compass",InstallMongoDBCompass},
        {"MongoDB",InstallMongoDB},{"MongoDB Atlas",InstallMongoDBAtlas},{"NodeJS",InstallNodeJS},{"GoLang",InstallGoLang},
        {"Python 3.9",InstallPython3_9},{"Python 3.10",InstallPython3_10},{"Python 3.11",InstallPython3_11},
        {"JDK 18",InstallJDK_18},{"JDK 19",InstallJDK_19},{"Rust",InstallRust},{".Net Framework",InstallNetFramework},
        {"Ruby",InstallRuby},{"MSYS2",InstallMSYS2},{"Nuget",InstallNuget},
        {"GitHub Desktop",InstallGitHubDesktop},{"GitHub CLI",InstallGitHubCLi},{"Kubernetes",InstallKubernetes},
        {"Visual Studio Proffessional",InstallVisualStudioProffessional},{"Visual Studio Community",InstallVisualStudioCommunity}
    };
    map<string,funct_t> PythonDevelopmentTools {
        {"Python 3.9",InstallPython3_9},{"Python 3.10",InstallPython3_10},{"Python 3.11",InstallPython3_11},
        {"Git",InstallGit},{"VSCode",InstallVSCode},{"PyCharm Community",InstallPyCharmCommunity},
        {"PyCharm Proffessional",InstallPyCharmProffessional},{"Sublime Text",InstallSublimeText},{"Docker",InstallDocker},
        {"Postman",InstallPostman},{"Postgresql",InstallPostgresql},{"MongoDB",InstallMongoDB},
        {"MongoDB Atlas",InstallMongoDBAtlas},{"MongoDB Compass",InstallMongoDBCompass},
        {"Wget",InstallWget},{"Discord",InstallDiscord},{"Telegram",InstallTelegram},
        {"VNC Server",InstallVNCServer},{"VNC Viewer",InstallVNCViewer},{"GitHub Desktop",InstallGitHubDesktop},
        {"GitHub CLI",InstallGitHubCLi},{"Kubernetes",InstallKubernetes},{"JetBrains Fleet",InstallFleet},{"Visual Studio Proffessional",InstallVisualStudioProffessional},
        {"Visual Studio Community",InstallVisualStudioCommunity}
    };
    map<string,funct_t> JavaScriptDevelopmentTools {
        {"Git",InstallGit},{"VSCode",InstallVSCode},{"JetBrains WebStorm",InstallWebStorm},
        {"Docker",InstallDocker},{"Postman",InstallPostman},{"JetBrains Fleet",InstallFleet},
        {"Ngrok",InstallNgrok},{"Wget",InstallWget},{"Sublime Text",InstallSublimeText},
        {"Discord",InstallDiscord},{"Telegram",InstallTelegram},{"VNC Server",InstallVNCServer},{"VNC Viewer",InstallVNCViewer},
        {"MongoDB Compass",InstallMongoDBCompass},{"MongoDB",InstallMongoDB},{"MongoDB Atlas",InstallMongoDBAtlas},
        {"NodeJS",InstallNodeJS},{"GitHub Desktop",InstallGitHubDesktop},{"GitHub CLI",InstallGitHubCLi},
        {"Kubernetes",InstallKubernetes},{"Visual Studio Proffessional",InstallVisualStudioProffessional},
        {"Visual Studio Community",InstallVisualStudioCommunity}
    };
    map<string,funct_t> RustDevelopmentTools {
        {"Git",InstallGit},{"VSCode",InstallVSCode},{"Docker",InstallDocker},
        {"Postman",InstallPostman},{"JetBrains Fleet",InstallFleet},{"Wget",InstallWget},
        {"Sublime Text",InstallSublimeText},{"Discord",InstallDiscord},{"Telegram",InstallTelegram},
        {"VNC Server",InstallVNCServer},{"VNC Viewer",InstallVNCViewer},{"GitHub Desktop",InstallGitHubDesktop},{"GitHub CLI",InstallGitHubCLi},
        {"Kubernetes",InstallKubernetes},{"Rust",InstallRust},{"MongoDB",InstallMongoDB},{"MongoDB Atlas",InstallMongoDBAtlas},
        {"NodeJS",InstallNodeJS},{"MongoDB Compass",InstallMongoDBCompass},{"Visual Studio Proffessional",InstallVisualStudioProffessional},
        {"Visual Studio Community",InstallVisualStudioCommunity}
    };
    map<string,funct_t> RubyDevelopmentTools {
        {"Ruby",InstallRuby},{"RubyMine",InstallRubyMine},{"Git",InstallGit},{"VSCode",InstallVSCode},{"Docker",InstallDocker},
        {"Postman",InstallPostman},{"JetBrains Fleet",InstallFleet},{"Wget",InstallWget},
        {"Sublime Text",InstallSublimeText},{"Discord",InstallDiscord},{"Telegram",InstallTelegram},
        {"VNC Server",InstallVNCServer},{"VNC Viewer",InstallVNCViewer},{"GitHub Desktop",InstallGitHubDesktop},{"GitHub CLI",InstallGitHubCLi},
        {"Kubernetes",InstallKubernetes},{"MongoDB",InstallMongoDB},{"MongoDB Atlas",InstallMongoDBAtlas},
        {"NodeJS",InstallNodeJS},{"MongoDB Compass",InstallMongoDBCompass},{"Visual Studio Proffessional",InstallVisualStudioProffessional},
        {"Visual Studio Community",InstallVisualStudioCommunity}
    };
    map<string,funct_t> CppDevelopmentTools {

    };
    map<string,funct_t> CSDevelopmentTools {

    };
    map<string,funct_t> CDevelopmentTools {

    };
    map<string,funct_t> GoDevelopmentTools {

    };
    map<string,funct_t> JavaDevelopmentTools {

    };
    map<string,funct_t> PhpDevelopmentTools {

    };

    void PythonDevelopment() {
        for (const auto &element:PythonDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void JavaScriptDevelopment() {
        for (const auto &element:JavaScriptDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void RustDevelopment() {
        for (const auto &element:RustDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void RubyDevelopment() {
        for (const auto &element:RubyDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void CppDevelopment() {
        for (const auto &element:CppDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void CSDevelopment() {
        for (const auto &element:CSDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void CDevelopment() {
        for (const auto &element:CDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void GoDevelopment() {
        for (const auto &element:GoDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void JavaDevelopment() {
        for (const auto &element:JavaDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    void PHPDevelopment() {
        for (const auto &element:PhpDevelopmentTools) {
            string name = element.first;
            cout << name << endl;
            element.second();
        }
    }
    const funct_t PythonDevelop[1] = {InstallGit};
}