#include <iostream>
#include <chrono>    // timer functions
#include <cstdlib>   // rand

#include "mergesort.h"

int main() {

	/*
	MergeSort ms(10, 100);
	ms.print();
	ms.sort();
	ms.print();
	*/


	int n = 1;
	int range = 0;
	int trials = 0;

	while (n != 0) {
		std::cout << "size of heap: ";
		std::cin >> n;
		std::cout << std::endl << "range of heap: ";
		std::cin >> range;
		std::cout << std::endl << "trials: ";
		std::cin >> trials;
		std::cout << std::endl;

		// Start Timer
		auto begin = std::chrono::high_resolution_clock::now();
		for (auto i = 0; i < trials; i++)
		{
			// Start Test
				MergeSort ms(n, range);
				ms.sort();
				ms.print();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "duration:    " << duration << "ns." << std::endl;
	}
	return 0;
}