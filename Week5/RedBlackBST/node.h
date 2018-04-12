#pragma once
#include <string>
#include <memory>

const extern bool RED;
const extern bool BLACK;

class Node
{
public:
	Node(std::string key, int val, bool color);
	std::string key;
	int val;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	bool color;
};