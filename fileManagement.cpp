#include "fileManagement.h"

vector<string> getLinesOfFile(const string& filename)
{
    ifstream file; file.open(ROUTE + filename);
    vector<string> lines;
    string aux;
    getline(file,aux);
    while(file)
    {
        lines.push_back(aux);
        getline(file,aux);
    }
    return lines;
}

bool fileExists(const string& name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

ofstream fileForWriting(const string& filename)
{
    ofstream outfile;
    outfile.open(ROUTE + filename + extension);
    return outfile;
}
BasicTikZpicture obtainPureImage(const string& filename)
{
    ifstream file;
    file.open(ROUTE + filename + extension);
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

void savePureImage(const BasicTikZpicture& pic, const string& filename)
{
    auto file = fileForWriting(filename);
    for (string e : pic.colorDefinitions)
    {
        file << e << "\n";
    }
    file << pic.generalOptions << "\n" << pic.clipOption << "\n";
    for (string e : pic.data)
    {
        file << e << "\n";
    }
    file << "\\end{tikzpicture}";
    file.close();
}