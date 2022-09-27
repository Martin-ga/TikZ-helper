#pragma once
#include "fileManagement.h"
#include "globalConstants.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <cassert>
using namespace std;

void runCollageCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData);