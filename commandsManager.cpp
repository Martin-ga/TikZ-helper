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
        // Structure of the arguments: name of new image,
        // then four coordinates for clip,
        // then list of the following:
        // {
        //      Name of file to be included
        //      Xmin, Ymin, Xmax, Ymax of the lattice which repeats the instance
        // }
        // Reminder: the instances should be drawn in [21875,21876] x [21875,21876]
        // since the code detects coordinates which have to be translated by looking
        // for that digit pattern. Do not use the pattern elsewhere.
        runCollageCommand(args, picturesData);
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
        // Structure of the arguments: name of new image,
        // then four coordinates for clip
        // and then list of files which are integrated.
        runMergeCommand(args, picturesData);
    }
    else if (cmd == "addTable")
    {
        // Structure of the arguments: output file, input file, coordinates, step in cm, color
        runTableCommand(args, picturesData);
    }
    else
    {
        cout << "The command " << cmd << " was not recognized,\nwe are stopping here for your own safety.\n";
        assert(false);
    }
}