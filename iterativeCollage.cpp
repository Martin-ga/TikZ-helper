#include "iterativeCollage.h"




void runCollageCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData)
{
    string dummy;
    cout << "First of all, give a file name which will be used to save everything.\n";
    string fileName;
    getline(cin, fileName);
    auto file = fileForWriting(fileName);
    string generalOptions;
    stringstream clipOption;
    {
    cout << "Provide Xmin, Ymin, Xmax, Ymax separated by spaces.\n";
    long double Xmin, Ymin, Xmax, Ymax;
    cin >> Xmin >> Ymin >> Xmax >> Ymax;
    getline(cin, dummy);
    clipOption << "\\clip(" << Xmin << "," << Ymin << ") rectangle (" << Xmax << "," << Ymax << ");";
    }
    set<string> colorDefinitions;
    vector<string> v;
    string goOn;
    do
    {

        cout << "Provide the name of a file you would like to use in the collage.\n";
        string fileName;
        getline (cin,fileName);
        auto currentData = obtainPureImage(fileName);
        generalOptions = currentData.generalOptions;
        for (auto e : currentData.colorDefinitions)
        {
            colorDefinitions.insert(e);
        }
        cout << "Provide Xmin, Ymin, Xmax, Ymax of the set of copies of this instance, separated by spaces.\n";
        int Xmin, Ymin, Xmax, Ymax;
        cin >> Xmin >> Ymin >> Xmax >> Ymax;
        getline(cin, dummy);
        for (int x = Xmin; x <= Xmax; x++)
        {
            for (int y = Ymin; y <= Ymax; y++)
            {
                for (string el : currentData.data)
                {
                    if (el == ""){continue;}
                    stringstream input;
                    input.str(el);
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
                                cout << "Error detected in line:\n" << el << "\n";
                                assert(false);
                            }
                            result += aux.str();
                        }
                        else
                        {
                            result.push_back(cache);
                        }
                    }
                    v.push_back(result);

                }
                
            }
        }
        cout << "Do you want to continue (y/n)?\n";
        cin >> goOn;

    } while (goOn == "y");
    file << "\\documentclass[12pt]{article}\n\\usepackage{pgfplots}\n\\pgfplotsset{compat=1.15}\n\\usepackage{mathrsfs}\n\\usetikzlibrary{arrows}\n\\pagestyle{empty}\n\\begin{document}\n";
    for (string e : colorDefinitions)
    {
        file << e << "\n";
    }
    file << generalOptions << "\n" << clipOption.str() << "\n";
    for (string e : v)
    {
        file << e << "\n";
    }
    file << "\\end{tikzpicture}\n\\end{document}";
    file.close();



}