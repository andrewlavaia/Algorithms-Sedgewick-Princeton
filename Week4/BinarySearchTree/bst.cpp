#include "bst.h"
#include<iostream>

BST::BST() {
	root = nullptr;
}

// Adds a new key/value pair or updates the 
// value if the key already exists in BST
void BST::put(std::string key, int val) {
	root = recursivePut(root, key, val);
}

// Fetch value for given key
int BST::get(std::string key) {
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
void BST::remove(std::string key) {
	root = recursiveRemove(root, key);
}

// return child with smallest key
std::shared_ptr<Node> BST::min(std::shared_ptr<Node> x) {
	while (x->left != nullptr) {
		x = x->left;
	}
	return x;
}

// Tests whether the first key is less than the second
bool BST::less(std::string key1, std::string key2) {
	return key1 < key2;
}

// Tests whether the first key is less than the second
bool BST::more(std::string key1, std::string key2) {
	return key1 > key2;
}

// Recursively traverses the tree to find key.
// If key exists, value is updated. 
// If key does not exist, new Node is created with key/value pair
std::shared_ptr<Node> BST::recursivePut(std::shared_ptr<Node> x, std::string key, int val) {
	// Key not found, return new node
	if (x == nullptr) {
		return std::shared_ptr<Node> (new Node(key, val));
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

	// end recursion
	return x;

}

// Recursively traverses the tree to find key.
// If key exists and only one child, delete key/value pair, replace with other child
// If key exists and two children, delete key/value pair, replace with successor
// If key does not exist, return null
std::shared_ptr<Node> BST::recursiveRemove(std::shared_ptr<Node> x, std::string key) {
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

std::shared_ptr<Node> BST::recursiveRemoveMin(std::shared_ptr<Node> x) {
	if (x->left == nullptr) {
		return x->right;
	}
	x->left = recursiveRemoveMin(x->left);
	return x;
}

void BST::print() {
	std::cout << root->val;
}