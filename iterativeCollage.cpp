#include "iterativeCollage.h"




void runCollageCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData)
{
    if (arguments.size() < 5)
    {
        cout << "Too few arguments for collage, quitting now for your safety.\n";
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
        Coordinates lattice = generateCoordinates(*(it+1),*(it+2),*(it+3),*(it+4));
        generalOptions = pic.generalOptions;
        coloursVector.push_back(pic.colorDefinitions);
        vector<string> individualTranslation;
        for (int x = lattice.Xmin; x <= lattice.Xmax; x++)
        {
            for (int y = lattice.Ymin; y <= lattice.Ymax; y++)
            {
                for (string el : pic.data)
                {
                    individualTranslation.push_back(transformStringInCollage(el, x, y));
                }
            }
        }
        dataVector.push_back(individualTranslation);

        it += 5;
    }

    picturesData[arguments[0]] = BasicTikZpicture(flattenSet(coloursVector), generalOptions, clipOption, flatten(dataVector));

}

string transformStringInCollage(const string& s, int x, int y)
{
    if (s == ""){return "";}
    stringstream input;
    input.str(s);
    string result;
    char cache;
    while (input.get(cache))
    {
        if ((char)(7) == cache)
        {
            long double f;
            input >> f; f -= MAGIC_NUMBER_LAST_DIGIT; f += x;
            stringstream aux; aux << f;
            char comma; input >> comma; aux << ",";
            char tk; input >> tk;
            input >> f; f -= MAGIC_NUMBER_LAST_DIGIT; f += y;
            aux << f;
            if (comma!=',' || tk!=token || (result[result.size()-1] >= '0' && result[result.size()-1] <= '9') || (!input))
            {
                cout << "The file happens to contain magic sequence in a random place.\nThe file will not be processed and everything will be stopped\nso nothing weird happens. Please check the file.\nTerribly sorry about this :( .\n";
                cout << "Error detected in line:\n" << s << "\n";
                assert(false);
            }
            result += aux.str();
        }
        else
        {
            result.push_back(cache);
        }
    }
    return result;
}