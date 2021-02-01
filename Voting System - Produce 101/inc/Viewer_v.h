#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include <time.h>
#include "singer.h"
#include <string.h>
#include <string>
using namespace std;

class Viewer_v {
public:
	Viewer_v();
	string vote(Singer& singer,string name);
	string see_info(Singer& singer,string name);
	string see_info_all(Singer& singer,int i);
	string see_graph(Singer& singer, int round, string name);
};
