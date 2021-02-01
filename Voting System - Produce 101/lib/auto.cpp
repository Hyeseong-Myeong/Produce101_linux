#include "auto.h"
Auto::Auto() { 
	srand((unsigned)time(NULL));
}
void Auto::startAuto(Singer& singer,bool checkTime) {
	system("clear");
	if (checkTime) {
		for (int i = 0; i < 200; i++) {
			singer.voted(rand() % (singer.singer_num()));
		}
		cout<<"done"<<endl;
	}
	else {
		cout << "Vote not available" << endl;
	}
	usleep(1500000);
	system("clear");
}
void Auto::makeGroup(Singer& singer) {
	system("clear");
	int groupNum;
	for (int i = 0; i < singer.singer_num(); i++) {
		if (singer.singer_num() > 15)
			groupNum = rand() % 15;
		else
			groupNum = rand() % (singer.singer_num());
		singer.grouped(i,65+groupNum);
	}
	cout<<"group setted"<<endl;
	usleep(300000);
}

void Auto::giveBenefit(Singer& singer) {
	int groupNum;
	for (int i = 0; i < singer.singer_num(); i++) {
		if (singer.singer_num() > 15)
			groupNum = rand() % 15;
		else
			groupNum = rand() % (singer.singer_num());
		groupNum = 65 + groupNum;
			if (singer.getGroup(i) == groupNum)
				singer.voted(i,50);
	}
	cout<<"benefit given"<<endl;
	usleep(1500000);
	system("clear");
}