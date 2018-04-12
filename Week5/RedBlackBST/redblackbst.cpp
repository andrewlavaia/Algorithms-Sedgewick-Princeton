#include "redblackbst.h"
#include <iostream>

RedBlackBST::RedBlackBST() {
	root = nullptr;
}

// Adds a new key/value pair or updates the 
// value if the key already exists in BST
void RedBlackBST::put(std::string key, int val) {
	root = recursivePut(root, key, val);
	root->color = BLACK; // root needs to be black or it will trip assertion error in flipColors()
}

// Fetch value for given key
int RedBlackBST::get(std::string key) {
	std::shared_ptr<Node> x = root;
	while (x != nullptr) {
		if (key == x->key) {
			return x->val;
		}
		else if (less(key, x->key)) {
			x = x->left;
		}
		else { // key > x->key 
			x = x->right;
		}
	}
	return NULL;
}

// Remove key/value pair from BST using Hibbard deletion
void RedBlackBST::remove(std::string key) {
	root = recursiveRemove(root, key);
}

// return child with smallest key
std::shared_ptr<Node> RedBlackBST::min(std::shared_ptr<Node> x) {
	while (x->left != nullptr) {
		x = x->left;
	}
	return x;
}

// Tests whether the first key is less than the second
bool RedBlackBST::less(std::string key1, std::string key2) {
	return key1 < key2;
}

// Tests whether the first key is less than the second
bool RedBlackBST::more(std::string key1, std::string key2) {
	return key1 > key2;
}

// Recursively traverses the tree to find key.
// If key exists, value is updated. 
// If key does not exist, new Node is created with key/value pair
std::shared_ptr<Node> RedBlackBST::recursivePut(std::shared_ptr<Node> x, std::string key, int val) {
	// Key not found, return new node
	if (x == nullptr) {
		return std::shared_ptr<Node>(new Node(key, val, RED));
	}

	// Key found
	if (key == x->key) {
		x->val = val;
	}

	// call recursivePut on left node
	else if (less(key, x->key)) {
		x->left = recursivePut(x->left, key, val);
	}

	// call recursivePut on right node
	else {
		x->right = recursivePut(x->right, key, val);
	}

	// rotate left if red link is on right instead of left
	if (isRed(x->right) && !isRed(x->left)) {
		x = rotateLeft(x);
	}

	// rotate right if two red left links in a row
	if (isRed(x->left) && isRed(x->left->left)) {
		x = rotateRight(x);
	}

	// flip colors if both left and right children are red
	if (isRed(x->left) && isRed(x->right)) {
		flipColors(x);
	}

	// end recursion
	return x;

}

// Recursively traverses the tree to find key.
// If key exists and only one child, delete key/value pair, replace with other child
// If key exists and two children, delete key/value pair, replace with successor
// If key does not exist, return null
std::shared_ptr<Node> RedBlackBST::recursiveRemove(std::shared_ptr<Node> x, std::string key) {
	// Key not found
	if (x == nullptr) {
		return nullptr;
	}

	// call recursiveRemove on left node
	if (less(key, x->key)) {
		x->left = recursiveRemove(x->left, key);
	}

	// call recursiveRemove on right node
	else if (more(key, x->key)) {
		x->right = recursiveRemove(x->right, key);
	}

	// Key found
	else {
		// no right child
		if (x->right == nullptr) {
			return x->left;
		}

		// no left child
		if (x->left == nullptr) {
			return x->right;
		}

		// replace with successor
		std::shared_ptr<Node> t = x;
		x = min(t->right); // get the smallest key that is larger than x
		x->right = recursiveRemoveMin(t->right);
		x->left = t->left;
	}

	// end recursion
	return x;
}

// Recursively traverses the tree to find minimum key below given Node.
std::shared_ptr<Node> RedBlackBST::recursiveRemoveMin(std::shared_ptr<Node> x) {
	if (x->left == nullptr) {
		return x->right;
	}
	x->left = recursiveRemoveMin(x->left);
	return x;
}

// not yet implemented
void RedBlackBST::print() {
	std::cout << root->val;
}

// checks whether the Node's color is RED
bool RedBlackBST::isRed(std::shared_ptr<Node> x) {
	if (x == nullptr) {
		return false;
	}
	return x->color == RED;
}

// switches the red link from left side to right side
std::shared_ptr<Node> RedBlackBST::rotateLeft(std::shared_ptr<Node> h) {
	assert(isRed(h->right));
	std::shared_ptr<Node> x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

// switches the red link from right side to left side
std::shared_ptr<Node> RedBlackBST::rotateRight(std::shared_ptr<Node> h) {
	assert(isRed(h->left));
	std::shared_ptr<Node> x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

// Flips both child nodes from RED to BLACK and switches
// parent node from BLACK to RED
void RedBlackBST::flipColors(std::shared_ptr<Node> h) {
	assert(!isRed(h));
	assert(isRed(h->left));
	assert(isRed(h->right));

	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}