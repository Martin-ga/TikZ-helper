#pragma once
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include "basicTikZpicture.h"
using namespace std;

struct Coordinates
{
    long double Xmin;
    long double Ymin;
    long double Xmax;
    long double Ymax;
    Coordinates(long double Xmin, long double Ymin, long double Xmax, long double Ymax):Xmin(Xmin), Ymin(Ymin), Xmax(Xmax), Ymax(Ymax) {}
};

vector<string> flattenSet(const vector<vector<string>>& colorsList);
vector<string> flatten(const vector<vector<string>>& colorsList);
string generateClipOption(Coordinates c);
Coordinates generateCoordinates(string XminStr, string YminStr, string XmaxStr, string YmaxStr);