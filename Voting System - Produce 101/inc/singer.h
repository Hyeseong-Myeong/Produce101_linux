#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

class Singer {
	vector<string> name;
	vector<int> age;
	vector<string> agent;
	vector<int> birth;
	vector<double> height;
	vector<int> votes;
	vector<int> group;
	vector<int> roundgrade1;
	vector<int> roundgrade2;
	vector<int> roundgrade3;
	vector<int> roundgrade4;
	vector<int> roundgrade5;
public:
	Singer();
	void setRoundgrade(int round, int grade = 0, int mode = 0);
	void setName(string name);
	void setAge(int age);
    void setAgent(string agent);
    void setBirth(int birth);
    void setHeight(double height);
	void setVotes(int votes = 0);
	void setGroup(int group = 63);
	void voted(int num,int add=1);
	void graded(int num, int grade,int round);
	int getVotes(int num); 
	string getName(int num);
	int getAge(int num);
	string getAgent(int num);
	double getHeight(int num);
	int getBirth(int num);
	int getGroup(int num);
	int getRoundgrade(int round,  int num);
	int singer_num();
	void grouped(int num,int group);
	void erase(int num,int round);
};
 