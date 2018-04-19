#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <memory>

// Hash Table that handles collisions with separate chaining linked lists
class HashTable {
public:
	HashTable(int M);
	void put(std::string key, int val);
	int getVal(std::string key);

private:
	class Node {
		Node(std::string key, int val);
		std::string key;
		int val;
		std::shared_ptr<Node> next;
	};
	
	const int M;															// number of hash buckets 
	std::vector< std::shared_ptr<Node> > st;	// array of linked lists for chaining   

	int hash(std::string key);
};

#endif

