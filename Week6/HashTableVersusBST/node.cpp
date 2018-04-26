#include "node.h"

const extern bool RED = true;
const extern bool BLACK = false;

Node::Node(std::string key, int val, bool color) : key(key), val(val), color(color) {
	left = nullptr;
	right = nullptr;
}