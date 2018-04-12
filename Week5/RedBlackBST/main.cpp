#include <iostream>
#include <cassert>

#include "node.h"
#include "redblackbst.h"


int main() {

	RedBlackBST bst;
	bst.put("f", 4);
	assert(bst.get("f") == 4);
	bst.put("d", 2);
	bst.put("z", 5);
	bst.put("r", 6);
	assert(bst.get("d") == 2);

	int n = 1;
	while (n != 0) {
		std::cin >> n;
	}

	return 0;
}