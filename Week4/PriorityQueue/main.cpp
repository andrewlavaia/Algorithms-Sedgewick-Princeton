#include <iostream>
#include <cassert>

#include "maxpq.h"

int main() {
	MaxPQ mpq; 
	mpq.insert(4);
	mpq.insert(2);
	mpq.insert(7);
	mpq.insert(3);
	mpq.insert(2);
	mpq.insert(7);
	mpq.insert(3);
	mpq.print();
	mpq.deleteMax();
	mpq.print();
	mpq.deleteMax();
	mpq.print();

	int x = 1;
	while (x != 0) {
		std::cin >> x;
	}
	return 0;
}