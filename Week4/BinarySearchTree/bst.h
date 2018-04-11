#pragma once
#include <string>
#include "node.h"

class BST
{
public:
	BST();
	void put(std::string key, int val);		// adds a new key/value pair, or updates value if key exists
	int get(std::string key);							// returns value when given key
	void remove(std::string key);					// removes key/value pair from BST
	void print();													// prints the entire BST (not optimized)

private: 
	std::shared_ptr<Node> root;
	bool less(std::string key1, std::string key2);
	bool more(std::string key1, std::string key2);
	std::shared_ptr<Node> min(std::shared_ptr<Node> x);

	std::shared_ptr<Node> recursivePut(std::shared_ptr<Node> x, std::string key, int val);
	std::shared_ptr<Node> recursiveRemove(std::shared_ptr<Node> x, std::string key);
	std::shared_ptr<Node> recursiveRemoveMin(std::shared_ptr<Node> x);
};