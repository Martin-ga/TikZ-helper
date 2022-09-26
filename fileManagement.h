#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "basicTikZpicture.h"
#include "globalConstants.h"
using namespace std;

vector<string> getLinesOfFile(const string& filename);
void savePureImage(const BasicTikZpicture& pic, const string& filename);
ofstream fileForWriting(const string& filename);
BasicTikZpicture obtainPureImage(const string& file);