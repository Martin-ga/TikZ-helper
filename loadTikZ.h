#pragma once
#include "fileManagement.h"
#include "basicTikZpicture.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <map>

void runLoadCommand(const vector<string>& arguments, map<string,BasicTikZpicture>& picturesData);