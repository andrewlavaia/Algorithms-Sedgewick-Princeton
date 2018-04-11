#include "node.h"

Node::Node(std::string key, int val) : key(key), val(val) {
	left = nullptr;
	right = nullptr;
}