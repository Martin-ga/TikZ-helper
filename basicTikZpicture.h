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
    BasicTikZpicture(vector<string> colDef, string option1, string option2, vector<string> data) : colorDefinitions(colDef), generalOptions(option1), clipOption(option2), data(data) {}
};
