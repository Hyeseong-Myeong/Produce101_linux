#pragma once
#include "viewer.h"

class Manager :public Viewer {
	int round;
   	struct timespec start;
public:
	Manager();
	void file_open(Singer& singer);
	void file_save(Singer& singer);
	void change(Singer& singer);
	void erase(Singer& singer);
	void startvote(Singer& singer);
	bool checktime();
	void setround(int round);
	int getround();
	void grading(Singer& singer);
};
