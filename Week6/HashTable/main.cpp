#include <iostream>
#include "hashtable.h"

int main() {

	int n = 1;
	while (n != 0) {
		std::cout << "# of Hash Buckets :";
		std::cin >> n;
		std::cout << std::endl;

		HashTable ht(n);

	}

	return 0;
}