# Installing libraries 
YUM_PACKAGE_NAME="jsoncpp jsoncpp-devel make cmake g++ gcc gtest-devel gtest gmock-devel gmock curl libcurl-devel libcurl sqlite-devel sqlite-tcl libstdc++.x86_64 libstdc++-devel.x86_64 libstdc++-static.x86_64" 
DEB_PACKAGE_NAME="g++ gcc build-essential cmake make curl libcurl4-openssl-dev libjsoncpp-dev libfmt-dev libsqlite3-dev libgtest-dev googletest google-mock libgmock-dev libtbb-dev" 
PACMAN_PACKAGE_NAME="jsoncpp gcc base-devel cmake clang gtest lib32-curl libcurl-compat libcurl-gnutls curl fmt lib32-sqlite sqlite sqlite-tcl" 
ZYPPER_PACKAGE_NAME="" 
if [[ "$OSTYPE" == "linux-gnu"* ]]; then 
    if cat /etc/*release | grep ^NAME | grep CentOS; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo yum update -y 
        sudo yum install -y $YUM_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep Red; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo yum update -y 
        sudo yum install -y $YUM_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep Fedora; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo yum update -y 
        sudo yum install -y $YUM_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep Ubuntu; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo add-apt-repository universe 
        sudo apt-get update 
        sudo apt-get install -y $DEB_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep Debian ; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo add-apt-repository universe 
        sudo apt-get update 
        sudo apt-get install -y $DEB_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep Mint ; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo add-apt-repository universe 
        sudo apt-get update 
        apt-get install -y $DEB_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep Knoppix ; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo add-apt-repository universe 
        sudo apt-get update 
        sudo apt-get install -y $DEB_PACKAGE_NAME 
    elif cat /etc/*release | grep ^NAME | grep "Manjaro Linux" ; then 
        echo "================================================" 
        echo "Installing libraries" 
        echo "================================================" 
        sudo pacman -Sy jsoncpp 
        sudo pacman -Sy gcc 
        sudo pacman -Sy base-devel 
        sudo pacman -Sy cmake 
        sudo pacman -Sy clang 
        sudo pacman -Sy gtest 
        sudo pacman -Sy lib32-curl 
        sudo pacman -Sy libcurl-compat 
        sudo pacman -Sy libcurl-gnutls 
        sudo pacman -Sy curl 
        sudo pacman -Sy fmt 
        sudo pacman -Sy lib32-sqlite 
        sudo pacman -Sy sqlite 
        sudo pacman -Sy sqlite-tcl 
    else 
        echo "Not found package manager" 
        exit 1; 
    fi 
elif [[ "$OSTYPE" == "darwin"* ]]; then 
    # Mac OSX 
    # echo "macOS" 
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" 
    brew install jsoncpp sqlite3 sqlite-utils fmt clang-format curl googletest gcc 
fi 
echo "==> Libraries successfully installed" 
unameOut=$(uname -a) 
case "${unameOut}" in 
Darwin*) os="macOS";; 
Linux*) os="Linux";; 
esac
echo "==> Building tests"
g++ ./src/tests/MainTest.cpp -o ./tests/MainTest -static-libgcc -static-libstdc++ -lsqlite3 -ljsoncpp -lcurl -lgtest -lgmock -pthread -std=c++2a
echo "==> Build of tests finished"
echo "==> Running tests"
sudo ./tests/MainTest