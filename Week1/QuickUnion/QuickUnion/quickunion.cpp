
#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>    // timer functions
#include <cstdlib>   // rand

class QU
{
public:
	QU(int n);
	int findRoot(int i);
	void createUnion(int p, int q);
	bool isConnected(int p, int q);
	int getSize() { return m_size; };

private:
	int m_size;
	std::vector<int> m_id;
};

QU::QU(int n) {
	m_size = n;

	for (int i = 0; i < n; i++) {
		m_id.push_back(i);
	}
}

int QU::findRoot(int i) {
	while (i != m_id[i]) {
		i = m_id[i];
	}
	return i;
}

void QU::createUnion(int p, int q) {
	int i = findRoot(p);
	int j = findRoot(q);

	m_id[i] = j;
}

bool QU::isConnected(int p, int q) {
	return findRoot(p) == findRoot(q);
}

int main()
{

	// unit tests for validity
	QU wquTest(10);
	assert(wquTest.findRoot(3) == 3);
	wquTest.createUnion(3, 5);
	assert(wquTest.findRoot(3) == 5);
	wquTest.createUnion(5, 8);
	wquTest.createUnion(8, 9);
	assert(wquTest.isConnected(3, 9));
	assert(!wquTest.isConnected(3, 7));

	int n = 1;
	while (n != 0) {
		std::cout << "Size of Vector: ";
		std::cin >> n;
		QU qu(n);

		int u;
		std::cout << "Number of random union operations: ";
		std::cin >> u;

		// Start Timer
		auto begin = std::chrono::high_resolution_clock::now();
		uint32_t iterations = 10000;
		for (uint32_t i = 0; i < iterations; ++i)
		{
			// Start Test
			for (int j = 0; j < u; j++) {
				qu.createUnion(rand() % qu.getSize(), rand() % qu.getSize());
			}

		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl << std::endl;

	}
	return 0;
}

