BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "Applications" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"macOS"	TEXT,
	"Linux"	TEXT
);
CREATE TABLE IF NOT EXISTS "CDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "PythonDevelopmentTools" (
	"Name"	INTEGER NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "DevelopmentPacks" (
	"Number"	TEXT NOT NULL,
	"Language"	TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS "RustDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "JavaScriptDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "CppDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "GoDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "RubyDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "CSDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "PHPDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "KotlinDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "JavaDevelopmentTools" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"Linux"	TEXT,
	"macOS"	TEXT
);
CREATE TABLE IF NOT EXISTS "Test" (
	"Name"	TEXT NOT NULL,
	"Windows"	TEXT,
	"macOS"	TEXT,
	"Linux"	TEXT
);
INSERT INTO "Applications" ("Name","Windows","macOS","Linux") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','brew install --cask visual-studio-code','sudo snap install code --classic'),
 ('Docker','winget install -e --id Docker.DockerDesktop','brew install --cask docker','sudo snap install docker'),
 ('Git','winget install --id Git.Git -e --source winget','brew install --cask git','ManualInstallation'),
 ('JetBrains WebStorm','winget install -e --id JetBrains.WebStorm','brew install --cask webstorm','sudo snap install webstorm --classic'),
 ('Postman','winget install -e --id Postman.Postman','brew install --cask postman','sudo snap install postman'),
 ('JetBrains RubyMine','winget install -e --id JetBrains.RubyMine','brew install --cask rubymine','sudo snap install postman'),
 ('JetBrains CLion','winget install -e --id JetBrains.CLion','brew install --cask clion','sudo snap install clion --classic'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','brew install --cask datagrip','sudo snap install datagrip --classic'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','brew install --cask dataspell','sudo snap install dataspell --classic'),
 ('Eclipse IDE','ManualInstallation','brew install --cask eclipse-ide','sudo snap install eclipse --classic'),
 ('JetBrains GoLand','winget install -e --id JetBrains.GoLand','brew install --cask goland','sudo snap install goland --classic'),
 ('JetBrains IntelliJ IDEA Community','winget install -e --id JetBrains.IntelliJIDEA.Community','brew install --cask intellij-idea-ce','sudo snap install intellij-idea-community --classic'),
 ('JetBrains IntelliJ IDEA Ultimate','winget install -e --id JetBrains.IntelliJIDEA.Ultimate','brew install --cask intellij-idea','sudo snap install intellij-idea-ultimate --classic'),
 ('JetBrains Rider','winget install -e --id JetBrains.Rider','brew install --cask rider','sudo snap install rider --classic'),
 ('JetBrains PhpStorm','winget install -e --id JetBrains.PHPStorm','brew install --cask phpstorm','sudo snap install phpstorm --classic'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','brew install --cask jetbrains-space','sudo snap install space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','brew install postgresql@14','sudo snap install postgresql'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4','winget install -e --id PostgreSQL.pgAdmin'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','brew install --cask ngrok','sudo snap install ngrok'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','brew install --cask sublime-text','sudo snap install sublime-text --classic'),
 ('JetBrains PyCharm Community','winget install -e --id JetBrains.PyCharm.Community','brew install --cask pycharm-ce','sudo snap install pycharm-community --classic'),
 ('JetBrains PyCharm Proffessional','winget install -e --id JetBrains.PyCharm.Professional','brew install --cask pycharm','sudo snap install pycharm-professional --classic'),
 ('Discord','winget install -e --id Discord.Discord','brew install --cask discord','sudo snap install discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','brew install --cask telegram','sudo snap install telegram-desktop'),
 ('NodeJS','winget install -e --id OpenJS.NodeJS','brew install node','sudo snap install node --classic'),
 ('Go','winget install -e --id GoLang.Go.1.18','brew install go','sudo snap install go --classic'),
 ('JDK 18','winget install -e --id Oracle.JDK.18','brew install openjdk@18','sudo snap install openjdk@18'),
 ('JDK 19','winget install -e --id Oracle.JDK.19','brew install openjdk@19','sudo snap install openjdk@19'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('Visual Studio','Not Found','brew install --cask visual-studio','Not Found'),
 ('Rust','winget install -e --id Rustlang.Rust.MSVC','brew install rust','sudo snap install rustup --classic'),
 ('Ruby','winget install -e --id RubyInstallerTeam.Ruby.3.1','brew install ruby','sudo snap install ruby --classic'),
 ('.Net Framework','winget install -e --id Microsoft.DotNet.Framework.DeveloperPack_4','brew install dotnet','sudo snap install dotnet-sdk --classic'),
 ('Python 3.9','winget install -e --id Python.Python.3.9','brew install python@3.9','ManualInstallation'),
 ('Python 3.10','winget install -e --id Python.Python.3.10','brew install python@3.10','ManualInstallation'),
 ('Python 3.11','winget install -e --id Python.Python.3.11','brew install python@3.11','ManualInstallation'),
 ('Vim','winget install -e --id vim.vim','brew install vim','sudo snap install vim-editor --beta'),
 ('NeoVim','winget install -e --id Neovim.Neovim','brew install neovim','sudo snap install nvim --classic'),
 ('vcpkg','ManualInstallation','brew install vcpkg','ManualInstallation'),
 ('Kotlin','ManualInstallation','brew install kotlin','sudo snap install kotlin --classic'),
 ('PHP','ManualInstallation','brew install php','ManualInstallation'),
 ('CMake','winget install -e --id Kitware.CMake','brew install cmake','sudo snap install cmake --classic'),
 ('Make','ManualInstallation','brew install make','ManualInstallation'),
 ('Conan Package Manager','winget install -e --id JFrog.Conan','brew install conan','ManualInstallation');
INSERT INTO "CDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains CLion','winget install -e --id JetBrains.CLion','sudo snap install clion --classic','brew install --cask clion'),
 ('vcpkg','ManualInstallation','ManualInstallation','brew install vcpkg'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','sudo snap install datagrip --classic','brew install --cask datagrip'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','sudo snap install dataspell --classic','brew install --cask dataspell'),
 ('CMake','winget install -e --id Kitware.CMake','sudo snap install cmake --classic','brew install cmake'),
 ('Make','ManualInstallation','ManualInstallation','brew install make'),
 ('Conan Package Manager','winget install -e --id JFrog.Conan','ManualInstallation','brew install conan'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "PythonDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Python 3.9','winget install -e --id Python.Python.3.9','ManualInstallation','brew install python@3.9'),
 ('Python 3.10','winget install -e --id Python.Python.3.10','ManualInstallation','brew install python@3.10'),
 ('Python 3.11','winget install -e --id Python.Python.3.11','ManualInstallation','brew install python@3.11'),
 ('JetBrains PyCharm Community','winget install -e --id JetBrains.PyCharm.Community','sudo snap install pycharm-community --classic','brew install --cask pycharm-ce'),
 ('JetBrains PyCharm Proffessional','winget install -e --id JetBrains.PyCharm.Professional','sudo snap install pycharm-professional --classic','brew install --cask pycharm'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','sudo snap install datagrip --classic','brew install --cask datagrip'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','sudo snap install dataspell --classic','brew install --cask dataspell'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "DevelopmentPacks" ("Number","Language") VALUES ('1','PythonDevelopmentTools'),
 ('2','JavaScriptDevelopmentTools'),
 ('3','CppDevelopmentTools'),
 ('4','JavaDevelopmentTools'),
 ('5','GoDevelopmentTools'),
 ('6','RustDevelopmentTools'),
 ('7','RubyDevelopmentTools'),
 ('8','CDevelopmentTools'),
 ('9','CSDevelopmentTools'),
 ('10','PHPDevelopmentTools'),
 ('11','KotlinDevelopmentTools');
INSERT INTO "RustDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('Rust','winget install -e --id Rustlang.Rust.MSVC','sudo snap install rustup --classic','brew install rust'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "JavaScriptDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains WebStorm','winget install -e --id JetBrains.WebStorm','sudo snap install webstorm --classic','brew install --cask webstorm'),
 ('NodeJS','winget install -e --id OpenJS.NodeJS','sudo snap install node --classic','brew install node'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','sudo snap install datagrip --classic','brew install --cask datagrip'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','sudo snap install dataspell --classic','brew install --cask dataspell'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "CppDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains CLion','winget install -e --id JetBrains.CLion','sudo snap install clion --classic','brew install --cask clion'),
 ('vcpkg','ManualInstallation','ManualInstallation','brew install vcpkg'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','sudo snap install datagrip --classic','brew install --cask datagrip'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','sudo snap install dataspell --classic','brew install --cask dataspell'),
 ('CMake','winget install -e --id Kitware.CMake','sudo snap install cmake --classic','brew install cmake'),
 ('Make','ManualInstallation','ManualInstallation','brew install make'),
 ('Conan Package Manager','winget install -e --id JFrog.Conan','ManualInstallation','brew install conan'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "GoDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains GoLand','winget install -e --id JetBrains.GoLand','sudo snap install goland --classic','brew install --cask goland'),
 ('Go','winget install -e --id GoLang.Go.1.18','sudo snap install go --classic','brew install go'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','sudo snap install datagrip --classic','brew install --cask datagrip'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','sudo snap install dataspell --classic','brew install --cask dataspell'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "RubyDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains RubyMine','winget install -e --id JetBrains.RubyMine','sudo snap install postman','brew install --cask rubymine'),
 ('Ruby','winget install -e --id RubyInstallerTeam.Ruby.3.1','sudo snap install ruby --classic','brew install ruby'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "CSDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains Rider','winget install -e --id JetBrains.Rider','sudo snap install rider --classic','brew install --cask rider'),
 ('.Net Framework','winget install -e --id Microsoft.DotNet.Framework.DeveloperPack_4','sudo snap install dotnet-sdk --classic','brew install dotnet'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "PHPDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JetBrains PhpStorm','winget install -e --id JetBrains.PHPStorm','sudo snap install phpstorm --classic','brew install --cask phpstorm'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('PHP','ManualInstallation','ManualInstallation','brew install php'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "KotlinDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('Eclipse IDE','ManualInstallation','sudo snap install eclipse --classic','brew install --cask eclipse-ide'),
 ('Kotlin','ManualInstallation','sudo snap install kotlin --classic','brew install kotlin'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
INSERT INTO "JavaDevelopmentTools" ("Name","Windows","Linux","macOS") VALUES ('VSCode','winget install -e --id Microsoft.VisualStudioCode','sudo snap install code --classic','brew install --cask visual-studio-code'),
 ('Docker','winget install -e --id Docker.DockerDesktop','sudo snap install docker','brew install --cask docker'),
 ('Git','winget install --id Git.Git -e --source winget','ManualInstallation','brew install --cask git'),
 ('Sublime Text','winget install -e --id SublimeHQ.SublimeText.4','sudo snap install sublime-text --classic','brew install --cask sublime-text'),
 ('Discord','winget install -e --id Discord.Discord','sudo snap install discord','brew install --cask discord'),
 ('Telegram','winget install -e --id Telegram.TelegramDesktop','sudo snap install telegram-desktop','brew install --cask telegram'),
 ('Visual Studio Community','winget install -e --id Microsoft.VisualStudio.2022.Community.Preview','Not Found','Not Found'),
 ('Visual Studio Proffessional','winget install -e --id Microsoft.VisualStudio.2022.Professional.Preview','Not Found','Not Found'),
 ('JDK 18','winget install -e --id Oracle.JDK.18','sudo snap install openjdk@18','brew install openjdk@18'),
 ('JDK 19','winget install -e --id Oracle.JDK.19','sudo snap install openjdk@19','brew install openjdk@19'),
 ('Eclipse IDE','ManualInstallation','sudo snap install eclipse --classic','brew install --cask eclipse-ide'),
 ('Postman','winget install -e --id Postman.Postman','sudo snap install postman','brew install --cask postman'),
 ('JetBrains Space','winget install -e --id JetBrains.Space','sudo snap install space','brew install --cask jetbrains-space'),
 ('Postgresql','winget install -e --id PostgreSQL.PostgreSQL','sudo snap install postgresql','brew install postgresql@14'),
 ('PgAdmin','winget install -e --id PostgreSQL.pgAdmin','winget install -e --id PostgreSQL.pgAdmin','brew install --cask pgadmin4'),
 ('Vim','winget install -e --id vim.vim','sudo snap install vim-editor --beta','winget install -e --id vim.vim'),
 ('NeoVim','winget install -e --id Neovim.Neovim','sudo snap install nvim --classic','brew install neovim'),
 ('Ngrok','winget install -e --id Ngrok.Ngrok','sudo snap install ngrok','brew install --cask ngrok'),
 ('Visual Studio','Not Found','Not Found','brew install --cask visual-studio'),
 ('JetBrains DataGrip','winget install -e --id JetBrains.DataGrip','sudo snap install datagrip --classic','brew install --cask datagrip'),
 ('JetBrains DataSpell','winget install -e --id JetBrains.DataSpell','sudo snap install dataspell --classic','brew install --cask dataspell'),
 ('Wget','ManualInstallation','ManualInstallation','brew install wget');
COMMIT;
