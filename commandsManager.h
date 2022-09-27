#pragma once
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <cassert>
#include "basicTikZpicture.h"
#include "saveTikZ.h"
#include "loadTikZ.h"
#include "merge.h"
using namespace std;

void processCommand(const string& s, map<string,BasicTikZpicture>& picturesData);