#include "utils.h"

vector<string> flattenSet(const vector<vector<string>>& colorsList)
{
    set<string> s;
    for (vector<string> indColors : colorsList)
    {
        for (string el : indColors)
        {
            s.insert(el);
        }
    }
    vector<string> result;
    for (string el : s)
    {
        result.push_back(el);
    }
    return result;
}

vector<string> flatten(const vector<vector<string>>& colorsList)
{
    vector<string> result;
    for (vector<string> indColors : colorsList)
    {
        for (string el : indColors)
        {
            result.push_back(el);
        }
    }
    return result;
}

string generateClipOption(Coordinates c)
{
    stringstream clipOption;
    clipOption << "\\clip(" << c.Xmin << "," << c.Ymin << ") rectangle (" << c.Xmax << "," << c.Ymax << ");";
    return clipOption.str();
}

Coordinates generateCoordinates(string XminStr, string YminStr, string XmaxStr, string YmaxStr)
{
    stringstream XminSS, YminSS, XmaxSS, YmaxSS;
    XminSS.str(XminStr);
    YminSS.str(YminStr);
    XmaxSS.str(XmaxStr);
    YmaxSS.str(YmaxStr);
    long double Xmin;
    long double Ymin;
    long double Xmax;
    long double Ymax;
    XminSS >> Xmin;
    YminSS >> Ymin;
    XmaxSS >> Xmax;
    YmaxSS >> Ymax;
    return {Xmin, Ymin, Xmax, Ymax};
}