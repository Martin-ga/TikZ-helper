#pragma once
#include <vector>
#include <string>
using namespace std;

struct BasicTikZpicture
{
    string option1;
    string option2;
    vector<string> data;
    BasicTikZpicture(string option1, string option2, vector<string> data) : option1(option1), option2(option2), data(data) {}
};
