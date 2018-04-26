#include <iostream>
#include <chrono>    // timer functions
#include <cstdlib>   // rand
#include <random>		

#include "hashtable.h"
#include "redblackbst.h"


std::string generateRandomString(int len)
{
	std::string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, len);
}

int main() {
	int buckets = 1;
	int nodes = 1;
	int sims = 1;
	while (sims != 0) {
		std::cout << "----------------------------" << std::endl;
		std::cout << "Hash Table vs Red Black BST" << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "# of Buckets in Hash Table: ";
		std::cin >> buckets;
		std::cout << std::endl;
		std::cout << "# of Nodes to Insert: ";
		std::cin >> nodes;
		std::cout << std::endl;
		std::cout << "# of Simulations to Run: ";
		std::cin >> sims;
		std::cout << std::endl;

		if (sims == 0)
			return 0;

		// Start BST Test Timer
		auto begin = std::chrono::high_resolution_clock::now();
		for (auto i = 0; i < sims; ++i) {
			RedBlackBST bst;
			for (auto j = 0; j < nodes; ++j)
			{

				bst.put(generateRandomString(16), rand() % 1000000);
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "BST Insertion - average duration:    " << duration/sims << " ns" << std::endl;

		// Start Hash Table Test Timer
		begin = std::chrono::high_resolution_clock::now();
		for (auto i = 0; i < sims; ++i) {
			HashTable ht(buckets);
			for (auto j = 0; j < nodes; ++j)
			{
				ht.put(generateRandomString(16), rand() % 1000000);
			}
		}
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "HT Insertion - average duration:     " << duration/sims << " ns" << std::endl;
		std::cout << std::endl;
	}

	return 0;
}