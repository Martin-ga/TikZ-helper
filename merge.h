#pragma once
#include <map>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <cassert>
#include "basicTikZpicture.h"
#include "utils.h"

using namespace std;
void runMergeCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData);