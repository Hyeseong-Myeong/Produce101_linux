#include "singer.h"

Singer::Singer() {
	name.clear();
	age.clear();
	agent.clear();
	height.clear();
	birth.clear();
	votes.clear();
	group.clear();
	roundgrade1.clear();
	roundgrade2.clear();
	roundgrade3.clear();
	roundgrade4.clear();
	roundgrade5.clear();
}

void Singer::setRoundgrade(int round, int grade, int mode) {
	if (mode == 1) {
		switch (round) {
		case 1:
			roundgrade1.push_back(grade);
			break;
		case 2:
			roundgrade2.push_back(grade);
			break;
		case 3:
			roundgrade3.push_back(grade);
			break;
		case 4:
			roundgrade4.push_back(grade);
			break;
		case 5:
			roundgrade5.push_back(grade);
			break;
		}
	}
	else {
		for (int i = 0; i < singer_num(); i++) {
			switch (round) {
			case 1:
				roundgrade1.push_back(grade);
				break;
			case 2:
				roundgrade2.push_back(grade);
				break;
			case 3:
				roundgrade3.push_back(grade);
				break;
			case 4:
				roundgrade4.push_back(grade);
				break;
			case 5:
				roundgrade5.push_back(grade);
				break;
			}
		}
	}
}
void Singer::setName(string name) {
	this->name.push_back(name);
}
void Singer::setAge(int age) {
	this->age.push_back(age);
}
void Singer::setAgent(string agent) {
	this->agent.push_back(agent);
}
void Singer::setBirth(int birth) {
	this->birth.push_back(birth);
}
void Singer::setHeight(double height) {
	this->height.push_back(height);
}
void Singer::setVotes(int votes) {
	this->votes.push_back(votes);
}
void Singer::setGroup(int group) {
	this->group.push_back(group);
}
void Singer::voted(int num, int add) {
	votes.at(num) += add;
}
void Singer::graded(int num, int grade, int round) {
	switch (round) {
	case 1:
		roundgrade1.at(num) = grade;
		break;
	case 2:
		roundgrade2.at(num) = grade;
		break;
	case 3:
		roundgrade3.at(num) = grade;
		break;
	case 4:
		roundgrade4.at(num) = grade;
		break;
	case 5:
		roundgrade5.at(num) = grade;
		break;
	}
}
int Singer::singer_num() {
	return name.size();
}
string Singer::getName(int num) {
	return name.at(num);
}

int Singer::getAge(int num) {
	return age.at(num);
}
int Singer::getVotes(int num) {
	return votes.at(num);
}
string Singer::getAgent(int num) {
	return agent.at(num);
}
double Singer::getHeight(int num) {
	return height.at(num);
}
int Singer::getBirth(int num) {
	return birth.at(num);
}
int Singer::getGroup(int num) {
	return group.at(num);
}
int Singer::getRoundgrade(int round, int num) {
	switch (round) {
	case 1:
		return roundgrade1.at(num);
	case 2:
		return roundgrade2.at(num);
	case 3:
		return roundgrade3.at(num);
	case 4:
		return roundgrade4.at(num);
	case 5:
		return roundgrade5.at(num);
	}
}
void Singer::grouped(int num, int group) {
	this->group.at(num) = group;
}

void Singer::erase(int num,int round) {
	name.erase(name.begin() + num);
	age.erase(age.begin()+num);
	agent.erase(agent.begin() + num);
	height.erase(height.begin() + num);
	birth.erase(birth.begin() + num);
	votes.erase(votes.begin() + num);
	group.erase(group.begin() + num);
	for (int i = 1; i <= round; i++) {
		if (i == 1)
			roundgrade1.erase(roundgrade1.begin() + num);
		else if (i == 2)
			roundgrade2.erase(roundgrade2.begin() + num);
		else if (i == 3)
			roundgrade3.erase(roundgrade3.begin() + num);
		else if (i == 4)
			roundgrade4.erase(roundgrade4.begin() + num);
		else if (i == 5)
		roundgrade5.erase(roundgrade5.begin() + num);
	}
}