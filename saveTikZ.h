#pragma once
#include "fileManagement.h"
#include "basicTikZpicture.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <map>

void runSaveCommand(const vector<string>& arguments, const map<string,BasicTikZpicture>& picturesData);