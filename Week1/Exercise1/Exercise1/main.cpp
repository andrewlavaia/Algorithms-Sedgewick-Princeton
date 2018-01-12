
#include <iostream>
#include <vector>
#include <string>

class LogEntry {
public:
	int ts;
	std::string m1;
	std::string m2;

	LogEntry(int timestamp, std::string member1, std::string member2) {
		ts = timestamp;
		m1 = member1;
		m2 = member2;
	}
};

class LogFile {
public:
	std::vector<LogEntry> logs;

	void insert(LogEntry log) {
		logs.push_back(log);
	}
};

class Member {
public:
	int id;
	std::string name;

	Member(int ID, std::string NAME) {
		id = ID;
		name = NAME;
	}
};

class MemberList {
public:
	std::vector<Member> members;
	std::vector<int> friends;
	std::vector<int> friendNum;

	void add(std::string m) {
		members.push_back(Member(lastID, m));
		friends.push_back(lastID);
		lastID++;
	}

	int findRoot(int i) {
		while (i != friends[i]) {
			friends[i] = friends[friends[i]]; // skip a level and check grandparent 
			i = friends[i];
		}
		return i;
	}

	// union
	void createUnion(int p, int q) {
		int i = findRoot(p);
		int j = findRoot(q);

		// if roots are the same, p and q are already in the same set
		if (i == j) {
			return;
		}

		// move tree with less nodes into tree with more nodes
		if (friendNum[i] < friendNum[j]) {
			friends[i] = j;
			friendNum[j] += friendNum[i];
		}
		else {
			friends[j] = i;
			friendNum[i] += friendNum[j];
		}
	}

	bool isFriends(int p, int q) {
		return findRoot(p) == findRoot(q);
	}

private:
	int lastID = 0;
	int lastTime = 0;

};

int main() {

	// initialize members
	MemberList members;
	members.add("Chris");
	members.add("John");
	members.add("Henry");
	members.add("Bob");
	members.add("Andrew");
	members.add("Tom");

	// initialize log
	LogFile log;
	log.insert(LogEntry(1, "Chris", "Andrew"));
	log.insert(LogEntry(2, "John", "Andrew"));
	log.insert(LogEntry(3, "Henry", "Andrew"));
	log.insert(LogEntry(4, "Bob", "Chris"));
	log.insert(LogEntry(5, "Bob", "Tom"));
	log.insert(LogEntry(6, "Bob", "Henry"));
	log.insert(LogEntry(7, "Tom", "Chris"));
	log.insert(LogEntry(8, "John", "Chris"));



	return 0;
}