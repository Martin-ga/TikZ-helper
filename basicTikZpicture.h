#pragma once
#include <vector>
#include <string>
using namespace std;

struct BasicTikZpicture
{
    vector<string> colorDefinitions;
    string generalOptions;
    string clipOption;
    vector<string> data;
    BasicTikZpicture() : colorDefinitions(), generalOptions(), clipOption(), data() {}
    BasicTikZpicture(vector<string> colorDefinitions, string generalOptions, string clipOption, vector<string> data) : colorDefinitions(colorDefinitions), generalOptions(generalOptions), clipOption(clipOption), data(data) {}
};
