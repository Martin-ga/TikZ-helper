#include "fileManagement.h"




ofstream fileForWriting(string filename)
{
    ofstream outfile;
    outfile.open(filename + extension);
    return outfile;
}
BasicTikZpicture obtainPureImage(string filename)
{
    ifstream file;
    file.open(filename + extension);
    vector<string> vs;
    string aux; getline(file,aux);
    while (aux != "\\begin{document}")
    {
        getline(file,aux);
    }
    string d1, d2;
    getline(file,d1);
    vector<string> colorDefinitions;
    while (d1.substr(0,12) == "\\definecolor")
    {
        colorDefinitions.push_back(d1); getline(file,d1);
    }
    getline(file,d2);
    getline(file,aux);
    vector<string> v;
    do {
        size_t pos = 0;
        while (pos += 1)
        {
            pos = aux.find(MAGIC_STRING, pos);
            if (pos == std::string::npos) {
                break;
            }

            aux.erase(pos, MAGIC_STRING.length());
            string ss; ss.push_back(token);
            aux.insert(pos, ss);
        }
        v.push_back(aux);
        getline(file,aux);
    } while (aux != "\\end{tikzpicture}");
    file.close();

    return {colorDefinitions,d1,d2,v};
    

}