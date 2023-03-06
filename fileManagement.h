#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "basicTikZpicture.h"
#include "globalConstants.h"
using namespace std;

vector<string> getLinesOfFile(const string& filename);
void savePureImage(const BasicTikZpicture& pic, const string& filename);
bool fileExists(const string& name);
ofstream fileForWriting(const string& filename);
BasicTikZpicture obtainPureImage(const string& file);