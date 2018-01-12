#include <iostream>
#include <assert.h>
#include <chrono>    // timer functions
#include <cstdlib>   // rand

#include "QF.h"
#include "QU.h"
#include "WQU.h"
#include "WQUPC.h"

int main()
{

	// Quick Find Tests
	QF qfTest(10);
	qfTest.createUnion(3, 5);
	qfTest.createUnion(5, 8);
	qfTest.createUnion(8, 9);
	assert(qfTest.isConnected(3, 9));
	assert(!qfTest.isConnected(3, 7));

	// Quick Union Tests
	QU quTest(10);
	assert(quTest.findRoot(3) == 3);
	quTest.createUnion(3, 5);
	assert(quTest.findRoot(3) == 5);
	quTest.createUnion(5, 8);
	quTest.createUnion(8, 9);
	assert(quTest.isConnected(3, 9));
	assert(!quTest.isConnected(3, 7));


	// Weighted Quick Union tests
	WQU wquTest(10);
	assert(wquTest.findRoot(3) == 3);
	wquTest.createUnion(3, 5);
	assert(wquTest.findRoot(5) == 3);
	wquTest.createUnion(5, 8);
	assert(wquTest.findRoot(8) == 3);
	wquTest.createUnion(8, 9);
	assert(wquTest.findRoot(9) == 3);
	assert(wquTest.isConnected(3, 9));
	assert(!wquTest.isConnected(3, 7));
	wquTest.createUnion(1, 2);
	wquTest.createUnion(1, 0);
	wquTest.createUnion(7, 0);
	wquTest.createUnion(6, 0);
	assert(wquTest.findRoot(6) == 1);
	wquTest.createUnion(1, 3);
	assert(wquTest.findRoot(3) == 1);

	// Weighted Quick Union with Path Compression tests
	WQUPC wqupcTest(10);
	assert(wqupcTest.findRoot(3) == 3);
	wqupcTest.createUnion(3, 5);
	assert(wqupcTest.findRoot(5) == 3);
	wqupcTest.createUnion(5, 8);
	assert(wqupcTest.findRoot(8) == 3);
	wqupcTest.createUnion(8, 9);
	assert(wqupcTest.findRoot(9) == 3);
	assert(wqupcTest.isConnected(3, 9));
	assert(!wqupcTest.isConnected(3, 7));
	wqupcTest.createUnion(1, 2);
	wqupcTest.createUnion(1, 0);
	wqupcTest.createUnion(7, 0);
	wqupcTest.createUnion(6, 0);
	assert(wqupcTest.findRoot(6) == 1);
	wqupcTest.createUnion(1, 3);
	assert(wqupcTest.findRoot(3) == 1);

	int n = 1;
	while (n != 0) {
		std::cout << "Size of Vector: ";
		std::cin >> n;

		QF qf(n);					// Quick Find
		QU qu(n);					// Quick Union
		WQU wqu(n);				// Weighted Quick Union
		WQUPC wqupc(n);		// Weighted Quick Union with Path Compression

		int u;
		std::cout << "Number of random union operations: ";
		std::cin >> u;

		uint32_t iterations = 100;

		// ------------------------------------------
		// Quick Find
		// ------------------------------------------

		// Start Timer
		auto begin = std::chrono::high_resolution_clock::now();
		for (uint32_t i = 0; i < iterations; ++i)
		{
			// Start Test
			for (int j = 0; j < u; j++) {
				qf.createUnion(rand() % qf.getSize(), rand() % qf.getSize());
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "QF average:    " << duration / iterations << "ns." << std::endl;

		
		// ------------------------------------------
		// Quick Union
		// ------------------------------------------

		// Start Timer
		begin = std::chrono::high_resolution_clock::now();
		for (uint32_t i = 0; i < iterations; ++i)
		{
			// Start Test
			for (int j = 0; j < u; j++) {
				qu.createUnion(rand() % qu.getSize(), rand() % qu.getSize());
			}
		}
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "QU average:    " << duration / iterations << "ns." << std::endl;
		

		// ------------------------------------------
		// Weighted Quick Union
		// ------------------------------------------

		// Start Timer
		begin = std::chrono::high_resolution_clock::now();
		for (uint32_t i = 0; i < iterations; ++i)
		{
			// Start Test
			for (int j = 0; j < u; j++) {
				wqu.createUnion(rand() % wqu.getSize(), rand() % wqu.getSize());
			}
		}
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "WQU average:   " << duration / iterations << "ns." << std::endl;


		// ------------------------------------------
		// Weighted Quick Union With Path Compression
		// ------------------------------------------

		// Start Timer
		begin = std::chrono::high_resolution_clock::now();
		for (uint32_t i = 0; i < iterations; ++i)
		{
			// Start Test
			for (int j = 0; j < u; j++) {
				wqupc.createUnion(rand() % wqupc.getSize(), rand() % wqupc.getSize());
			}
		}
		end = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "WQUPC average: " << duration / iterations << "ns." << std::endl << std::endl;

	}
	return 0;
}