#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include <time.h>
#include "singer.h"
using namespace std;

class Viewer {
public:
	Viewer();
	void vote(Singer& singer);
	void see_info(Singer& singer);
	void see_info_all(Singer& singer);
	void see_graph(Singer& singer, int round);
};
