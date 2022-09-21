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
    string aux; file >> aux;
    while (aux != "\\begin{document}")
    {
        file >> aux;
    }
    string d1, d2;
    file >> d1 >> d2;
    file >> aux;
    vector<string> v;
    do {
        size_t pos = 0;
        while (pos += token.length())
        {
            pos = aux.find(MAGIC_STRING, pos);
            if (pos == std::string::npos) {
                break;
            }

            aux.erase(pos, MAGIC_STRING.length());
            aux.insert(pos, token);
        }
        v.push_back(aux);
        cin >> aux;
    } while (aux != "\\end{tikzpicture}");
    file.close();

    return {d1,d2,v};
    

}