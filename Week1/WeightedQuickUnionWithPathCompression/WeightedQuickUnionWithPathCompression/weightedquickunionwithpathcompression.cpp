
#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>    // timer functions
#include <cstdlib>   // rand

// weighted quick union with path compression
class WQUPC
{
public:
	WQUPC(int n);
	int findRoot(int i);
	void createUnion(int p, int q);
	bool isConnected(int p, int q);
	int getSize() { return m_size; };

private:
	int m_size;
	std::vector<int> m_id;
	std::vector<int> m_nodeCount;
};

WQUPC::WQUPC(int n) {
	m_size = n;

	for (int i = 0; i < n; i++) {
		m_id.push_back(i);
		m_nodeCount.push_back(1);
	}
}

int WQUPC::findRoot(int i) {
	while (i != m_id[i]) {
		m_id[i] = m_id[m_id[i]]; // skip a level and check grandparent 
		i = m_id[i];
	}
	return i;
}

void WQUPC::createUnion(int p, int q) {
	int i = findRoot(p);
	int j = findRoot(q);

	// if roots are the same, p and q are already in the same set
	if (i == j) {
		return;
	}

	// move tree with less nodes into tree with more nodes
	if (m_nodeCount[i] < m_nodeCount[j]) {
		m_id[i] = j;
		m_nodeCount[j] += m_nodeCount[i];
	}
	else {
		m_id[j] = i;
		m_nodeCount[i] += m_nodeCount[j];
	}
}

bool WQUPC::isConnected(int p, int q) {
	return findRoot(p) == findRoot(q);
}

int main()
{
	// unit tests for validity
	WQUPC wquTest(10);
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

	int n = 1;
	while (n != 0) {
		std::cout << "Size of Vector: ";
		std::cin >> n;
		WQUPC wqu(n);

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
				wqu.createUnion(rand() % wqu.getSize(), rand() % wqu.getSize());
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl << std::endl;

	}
	return 0;
}

