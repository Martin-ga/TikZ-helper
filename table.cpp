#include "table.h"

void runTableCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData)
{
    if (arguments.size() != 8)
    {
        cout << "Incorrect number of arguments for table, quitting now for your safety.\n";
        assert(false);
    }
    auto& originalPic = picturesData[arguments[1]];
    BasicTikZpicture modifiedPic = {originalPic.colorDefinitions,originalPic.generalOptions,originalPic.clipOption,vector<string>()};
    stringstream tableEntry;
    tableEntry << "\\draw[step=" << arguments[6] << "cm," << arguments[7] << ",very thin] (";
    tableEntry << arguments[2] << "," << arguments[3] << ") grid (" << arguments[4] << "," << arguments[5] << ");";
    modifiedPic.data.push_back(tableEntry.str());
    for (string s : originalPic.data)
    {
        modifiedPic.data.push_back(s);
    }
    picturesData[arguments[0]] = modifiedPic;
}

