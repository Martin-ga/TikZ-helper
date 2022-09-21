#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "basicTikZpicture.h"
#include "globalConstants.h"
using namespace std;

ofstream fileForWriting(string filename);
BasicTikZpicture obtainPureImage(string file);