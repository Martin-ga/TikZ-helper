#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include "iterativeCollage.h"
#include "fileManagement.h"
#include "globalConstants.h"
#include "commandsManager.h"
using namespace std;

void processCurrentRoute()
{
    vector<string> commands = getLinesOfFile(COMMANDS_FILE);
    map<string,BasicTikZpicture> picturesData;
    for (string s : commands)
    {
        cout << "Processing " << s << "...\n";
        processCommand(s, picturesData);
        cout << "The command was successfully processed.\n";
    }
}

int main()
{
    string path = ".";
    if (!fileExists("./.tikzhelperWork"))
    {
        cout << "Work file not found, leaving now.\n";
        cout << "If you want TikZhelper to work, add a file .tikzhelperWork.\n";
        return 0;
    }
    cout << "Work file found.\n";
    for (const auto& entry : filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            ROUTE = entry.path().string();
            ROUTE += "/";
            if (fileExists(ROUTE+".tikzhelperSkip"))
            {
                cout << "Found skip file (.tikzhelperSkip) in " << ROUTE;
                cout << "\nDirectory skipped. Delete skip file if not intended.\n";
            }
            else
            {
                cout << "Processing directory " << ROUTE << " ...\n";
                processCurrentRoute();
                cout << "Route processed successfully.\n";
            }
        }
    }
    cout << "All work done, have a nice day.\n" << flush;
    return 0;
}