#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include "iterativeCollage.h"
#include "fileManagement.h"
#include "globalConstants.h"
#include "commandsManager.h"
using namespace std;

int processCurrentRoute()
{
    vector<string> commands = getLinesOfFile(COMMANDS_FILE);
    map<string,BasicTikZpicture> picturesData;
    for (string s : commands)
    {
        cout << "Processing " << s << "...\n";
        processCommand(s, picturesData);
        cout << "The command was successfully processed.\n";
    }
    cout << "Have a nice day.\n" << flush;
    return 0;
}

int main()
{
    bool work = false;
    string path = ".";
    for (const auto& entry : filesystem::directory_iterator(path))
    {
        if (entry.path().string() == "./.tikzhelperWork")
        {
            work = true;
        }
    }
    if (!work)
    {
        cout << "Work file not found, leaving now.\n";
        cout << "If you want TikZhelper to work, add a file .tikzhelperWork and all directories will be processed.\n";
        return 0;
    }
    cout << "Work file found.\n";
    for (const auto& entry : filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            ROUTE = entry.path().string();
            ROUTE += "/";
            cout << "Processing directory " << ROUTE << " ...\n";
            processCurrentRoute();
            cout << "Route processed successfully.\n";
        }
    }
    return 0;
}