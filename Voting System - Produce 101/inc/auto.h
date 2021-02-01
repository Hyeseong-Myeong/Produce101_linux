#include "singer.h"
#include <time.h>
#include <stdlib.h>

class Auto {
public:
	Auto();
	void startAuto(Singer& singer, bool checkTime);
	void makeGroup(Singer& singer);
	void giveBenefit(Singer& singer);
};