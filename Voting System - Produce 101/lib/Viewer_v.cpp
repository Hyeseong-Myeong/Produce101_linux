#include "Viewer_v.h"
#include <stdio.h>
#define INFO_DATA "Name: %s\nAge: %d\nAgent: %s\nHeight: %f\nBirth: %d\nVotes: %d\nGroup: %c\n"
#define INFO_DATA_ALL "Name: %s\tAge: %d\tAgent: %s\tHeight: %f\tBirth: %d\tVotes: %d\tGroup: %c\n"
#define INFO_NODATA "%s does not exist.\n"
#define VOTE_SUCCESS "Voting success\n"
#define VOTE_FAIL "Singer named %s does not exist (vote Fail)\n"
Viewer_v::Viewer_v() { ; }

string Viewer_v::vote(Singer& singer,string name) {
	char inf[999999];
	
	for (int i = 0; i < singer.singer_num(); i++) {
		if (name == singer.getName(i)) {
			singer.voted(i);
			sprintf(inf,VOTE_SUCCESS);
			
			return inf;
		}
	}
	sprintf(inf,VOTE_FAIL,name.c_str());
	return inf;
}

string Viewer_v::see_info(Singer& singer,string name) {
    char info[999999];
	for (int i = 0; i < singer.singer_num(); i++) {
		if (name == singer.getName(i)) {
            sprintf(info,INFO_DATA,singer.getName(i).c_str(), singer.getAge(i), singer.getAgent(i).c_str(), singer.getHeight(i), singer.getBirth(i), singer.getVotes(i), (char)singer.getGroup(i));
            return info;
		}
	}
	sprintf(info,INFO_NODATA,name.c_str());
    return info;
}
string Viewer_v::see_info_all(Singer& singer,int i) {
    char info[999999];
    sprintf(info,INFO_DATA_ALL,singer.getName(i).c_str(), singer.getAge(i), singer.getAgent(i).c_str(), singer.getHeight(i), singer.getBirth(i), singer.getVotes(i), (char)singer.getGroup(i));
    return info;
}

string Viewer_v::see_graph(Singer& singer, int round, string name) {
	if(round > 0) {
		ofstream out ("rank.dat");
		out << "x\tname" << endl;
		for (int i = 0; i < singer.singer_num(); i++) {
			if (name == singer.getName(i)) {
				for(int j = 0; j < round; j++) {
					out << j + 1 << "\t" << singer.getRoundgrade(j+1, i);
					if (i == singer.singer_num());
					else{
						out << endl;
						out.close();
						return "data made\n";
					}
				}
			}
		}
		char data[1000];
		sprintf(data,"%s does not exist.\n",name.c_str());
		return data;
	}
} 
