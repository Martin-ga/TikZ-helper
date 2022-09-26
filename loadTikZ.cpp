#include "loadTikZ.h"
using namespace std;



void runLoadCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData)
{
    for (string fileName : arguments)
    {
        auto abstractImage = obtainPureImage(fileName);
        picturesData[fileName] = abstractImage;
    }
}