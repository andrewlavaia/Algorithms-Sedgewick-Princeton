#pragma once
#include <string>
#include <memory>

class Node
{
public:
	Node(std::string key, int val);
	std::string key;
	int val;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
};