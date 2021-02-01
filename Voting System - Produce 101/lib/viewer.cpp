#include "viewer.h"
Viewer::Viewer() { ; }

void Viewer::vote(Singer& singer) {
	system("clear");
    string name;
    cout << "Input name of singer to vote>>";
    cin >> name;
	for (int i = 0; i < singer.singer_num(); i++) {
		if (name == singer.getName(i)) {
			singer.voted(i);
			cout<<"Voting success"<<endl;
			usleep(1000000);
			system("clear");
			return;
		}
	}
	cout <<"Singer named " << name << " does not exist (vote Fail)" << endl;
	usleep(1500000);
	system("clear");
}

void Viewer::see_info(Singer& singer) {
	system("clear");
	string name;
	cout << "Input name of singer to see>>";
	cin >> name;
	for (int i = 0; i < singer.singer_num(); i++) {
		if (name == singer.getName(i)) {
			cout << "Name: " << singer.getName(i) << endl;
			cout << "Age: " << singer.getAge(i) << endl;
			cout << "Agent: " << singer.getAgent(i) << endl;
			cout << "Height: " << singer.getHeight(i) << endl;
			cout << "Birth: " << singer.getBirth(i) << endl;
			cout << "Votes: " << singer.getVotes(i) << endl;
			cout << "Group: " << (char)singer.getGroup(i) << endl;
			usleep(3000000);
			system("clear");
			return;
		}
	}
	cout << name << " does not exist." << endl;
	usleep(1500000);
	system("clear");
}
void Viewer::see_info_all(Singer& singer) {
	system("clear");
	for (int i = 0; i < singer.singer_num(); i++) {
		cout << "Name: " << singer.getName(i) << "\t";
		cout << "Age: " << singer.getAge(i) << "\t";
		cout << "Agent: " << singer.getAgent(i) << "\t";
		cout << "Height: " << singer.getHeight(i) << "\t";
		cout << "Birth: " << singer.getBirth(i) << "\t";
		cout << "Vote: " << singer.getVotes(i) << "\t";
		cout << "Group: " << (char)singer.getGroup(i) << endl;
	}
	usleep(5000000);
	system("clear");
}

void Viewer::see_graph(Singer& singer, int round) {
	system("clear");
	string name;
	cout << "Input name of singer to see graph>>";
	cin >> name;
	if(round > 0) {
		ofstream out ("rank.dat");
		out << "x\tname" << endl;
		for (int i = 0; i < singer.singer_num(); i++) {
			if (name == singer.getName(i)) {
				for(int j = 0; j < round; j++) {
					out << j + 1 << "\t" << singer.getRoundgrade(j+1, i);
					if (i == singer.singer_num());
					else
						out << endl;
				}
			}
		}
		out.close();
		system("chmod +x graph.sh");
		system("./graph.sh");
		usleep(7000000);
		system("clear");
		return;
	}
	cout << name << "does not exist." << endl;
	system("clear");
} 
