#include <iostream>

#include "mergesort.h"

int main() {

	MergeSort ms(10, 100);
	ms.print();
	ms.sort();
	ms.print();

	int i = 1;
	while (i != 0) {
		std::cin >> i;
	}
	return 0;
}