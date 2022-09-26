#include "commandsManager.h"


void processCommand(const string& s, map<string,BasicTikZpicture>& picturesData)
{
    stringstream ss;
    ss.str(s);
    string cmd; ss >> cmd;
    vector<string> args;
    string aux;
    ss >> aux;
    while (ss)
    {
        args.push_back(aux);
        ss >> aux;
    }
    if (cmd == "collage")
    {

    }
    else if (cmd == "load")
    {
        // Structure of the arguments: list of files to be loaded
        runLoadCommand(args, picturesData);

    }
    else if (cmd == "save")
    {
        // Structure of the arguments: list of files to be saved
        runSaveCommand(args, picturesData);
    }
    else if (cmd == "merge")
    {

    }
    else if (cmd == "addTable")
    {

    }
    else
    {
        cout << "The command " << cmd << " was not recognized,\nwe are stopping here for your own safety.\n";
        assert(false);
    }
}