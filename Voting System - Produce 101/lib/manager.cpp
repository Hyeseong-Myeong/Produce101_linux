#include "manager.h"
#include "auto.h"
Manager::Manager() :Viewer() {  
	start.tv_sec = -1;
	round = 0;
}

void Manager::file_open(Singer& singer) {
	string name;
	int age;
	int birth;
	double height;
	string agent;
	int votes;
	int group;
	int round;
	int roundgrade;
	int grade;
	ifstream file("input.txt");
	if (file.is_open()) {
		file >> round;
		setround(round);
		while (!file.eof()) {
			file >> name;
			singer.setName(name);
			file >> age;
			singer.setAge(age);
			file >> agent;
			singer.setAgent(agent);
			file >> birth;
			singer.setBirth(birth);
			file >> height;
			singer.setHeight(height);
			file >> votes;
			singer.setVotes(votes);
			file >> group;
			singer.setGroup(group);
			if (round > 0) {
				for (int j = 1; j < round+1; j++) {
					file >> roundgrade;
					singer.setRoundgrade(j, roundgrade,1);
				}
			}
		}
	}
	else cout << "No File to read." << endl;
	file.close();
}

void Manager::file_save(Singer& singer) {
	ofstream out("input.txt");
	out << round << endl;
	for (int i = 0; i < singer.singer_num(); i++) {
		out << singer.getName(i) << " " << singer.getAge(i) << " " << singer.getAgent(i) << " " << singer.getBirth(i) << " " << singer.getHeight(i) << " " << singer.getVotes(i) << " " << singer.getGroup(i);
		if (round > 0) {
			for (int j = 1; j <= round; j++) {
				out << " " << singer.getRoundgrade(j,i);
			}
		}
		if (i == singer.singer_num() - 1)
			;
		else
			out << endl;
	}
	out.close();
}

void Manager::setround(int round) {
	this->round = round;
}
int Manager::getround() {
	return round;
}
void Manager::change(Singer& singer) {
	system("clear");
	string name;
	int age;
	string agent;
	int birth;
	double height;
	cout << "Input Information(name,age,agent,birth,height)>>";
	cin >> name >> age >> agent >> birth >> height;
	singer.setName(name);
	singer.setAge(age);
	singer.setAgent(agent);
	singer.setBirth(birth);
	singer.setHeight(height);
	singer.setVotes();
	singer.setGroup();
	for (int i = 1; i <= round; i++) {
		singer.setRoundgrade(i);
	}
}
void Manager::erase(Singer& singer) {
	system("clear");
	string name;
	cout << "Input name of singer to erase>>";
	cin >> name;
	for (int i = 0; i < singer.singer_num(); i++) {
		if (singer.getName(i) == name) {
			singer.erase(i,round);
			cout<<"deleted"<<endl;
			usleep(1500000);
			system("clear");
			return;
		}
	}
	cout <<"Singer named " << name << "does not exist (vote Fail)" << endl;
	usleep(1500000);
	system("clear");
}
void Manager::startvote(Singer& singer) {
	system("clear");
	if (round >= 5) {
		cout << "All Round is over!" << endl;
	}
	else if (checktime()) {
		cout << "Voting in Progress!" << endl;
	}
	else {
		round++;
		singer.setRoundgrade(round);
		cout<< "Round" << round << " has started." << endl;
		clock_gettime(CLOCK_MONOTONIC,&start);
	}
	usleep(1500000);
	system("clear");
}

bool Manager::checktime() {
	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC,&end);
	if (end.tv_sec - start.tv_sec > 30 || start.tv_sec == -1) {
		start.tv_sec = -1;
		return false;
	}
	else
		return true;
}

void Manager::grading(Singer& singer) {
	struct Info{
		int vote;
		int num;
		Info(int num, int vote) {
			this->vote = vote;
			this->num = num;
		}
	};
	vector<struct Info*> a;
	for(int i = 0; i < singer.singer_num(); i++) {
		a.push_back(new struct Info(i, singer.getVotes(i)));
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			if (a.at(i)->vote < a.at(j)->vote) {
				int num = a.at(j)->num;
				int vote = a.at(j)->vote;
				a.at(j) = a.at(i);
				a.erase(a.begin()+i);
				a.insert(a.begin()+i, new struct Info(num, vote));
			}
		}
	}
	int c = 1;
	for (int i = 0; i < a.size(); i++) {
		singer.graded(a.at(i)->num, c++,round);
	}
}