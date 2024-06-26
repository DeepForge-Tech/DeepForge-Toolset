#include <string>
// #include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Database/DatabaseAPI.hpp>
#include <filesystem>
#include <map>
#include <iostream>

using namespace std;
using namespace DB;

std::filesystem::path current_path = std::filesystem::current_path().generic_string();
string DB_PATH = current_path.parent_path().string() + "/src/DB/AppInstaller.db";
Database database;
string NameApp = "TestApp";
string Windows_Command = "Test_Windows_Command";
string macOS_Command = "Test_macOS_Command";
string Linux_Command = "Test_Linux_Command";
string Table = "Test";

TEST(DatabaseGroup, CreateValue)
{
    database.open(&DB_PATH);
    int RESULT = database.InsertApplicationsToTable(Table, NameApp, Windows_Command, macOS_Command, Linux_Command);
    EXPECT_EQ(RESULT, 0);
}

TEST(DatabaseGroup, GetValue)
{
    database.open(&DB_PATH);
    string RESULT;
    RESULT = database.GetValueFromDB(Table, NameApp, "Windows");
    // delete[] &AnswerDB;
    EXPECT_STREQ(Windows_Command.c_str(), RESULT.c_str());
    RESULT = database.GetValueFromDB(Table, NameApp, "Linux");
    // delete[] &AnswerDB;
    EXPECT_STREQ(Linux_Command.c_str(), RESULT.c_str());
    RESULT = database.GetValueFromDB(Table, NameApp, "macOS");
    // delete[] &AnswerDB;
    EXPECT_STREQ(macOS_Command.c_str(), RESULT.c_str());
}

TEST(DatabaseGroup, DeleteValue)
{
    database.open(&DB_PATH);
    int RESULT = database.RemoveApplicationFromTable(Table, NameApp);
    EXPECT_EQ(0, RESULT);
}

TEST(DatabaseGroup, GetAllValues)
{
    database.open(&DB_PATH);
    map<string, string> Packages = database.GetAllValuesFromDB("Applications", "Windows");
    EXPECT_LE(1, Packages.size());
}

TEST(DatabaseGroup, GetDevPack)
{
    database.open(&DB_PATH);
    map<string, string> DevelopmetPacks = database.GetDevPackFromDB("DevelopmentPacks", "Language");
    EXPECT_LE(1, DevelopmetPacks.size());
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}