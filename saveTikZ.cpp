#include "saveTikZ.h"
using namespace std;



void runSaveCommand(const vector<string>& arguments, const map<string,BasicTikZpicture>& picturesData)
{
    for (string imageName : arguments)
    {
        auto it = picturesData.find(imageName);
        if (it == picturesData.end())
        {
            cout << "Cannot find image with name " << imageName << ".\nStopping now for your own safety.\n";
            assert(false);
        }
        savePureImage(it->second, it->first);
    }
}