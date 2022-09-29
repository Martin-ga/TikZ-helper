#include <iostream>
#include <string>
#include <map>
#include "iterativeCollage.h"
#include "fileManagement.h"
#include "globalConstants.h"
#include "commandsManager.h"
using namespace std;

int main()
{
    cout << "Please, enter the route you would like to compile.\nUse / at the end.\n";
    getline(cin, ROUTE);
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