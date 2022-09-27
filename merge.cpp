#include "merge.h"

void runMergeCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData)
{
    if (arguments.size() < 5)
    {
        cout << "Too few arguments for merge, quitting now for your safety.\n";
        assert(false);
    }
    string clipOption = generateClipOption(generateCoordinates(arguments[1],arguments[2],arguments[3],arguments[4]));

    vector<vector<string>> coloursVector;
    vector<vector<string>> dataVector;
    string generalOptions;

    auto it = arguments.begin() + 5;
    while (it != arguments.end())
    {
        BasicTikZpicture& pic = picturesData[*it];
        generalOptions = pic.generalOptions;
        coloursVector.push_back(pic.colorDefinitions);
        dataVector.push_back(pic.data);
        it++;
    }

    picturesData[arguments[0]] = BasicTikZpicture(flattenSet(coloursVector), generalOptions, clipOption, flatten(dataVector));
}

