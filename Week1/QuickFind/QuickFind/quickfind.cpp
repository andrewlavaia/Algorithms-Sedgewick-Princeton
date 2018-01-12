
#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>    // timer functions
#include <cstdlib>   // rand

class QF
{
	public:
		QF(int n);
		void createUnion(int p, int q);
		bool isConnected(int p, int q);
		int getSize() { return m_size; };

	private:
		int m_size;
		std::vector<int> m_id;
};

QF::QF(int n) {
	m_size = n;

	for (int i = 0; i < n; i++) {
		m_id.push_back(i);
	}
}

void QF::createUnion(int p, int q) {
	if (m_id[p] != m_id[q]) {
		int pval = m_id[p];
		int qval = m_id[q];

		for (int i = 0; i < m_size; i++) {
			if (m_id[i] == pval) {
				m_id[i] = qval;
			}
		}
	}
}

bool QF::isConnected(int p, int q) {
	return m_id[p] == m_id[q];
}

int main()
{
	// unit tests for validity
	QF qfTest(10);
	qfTest.createUnion(3, 5);
	qfTest.createUnion(5, 8);
	qfTest.createUnion(8, 9);
	assert(qfTest.isConnected(3, 9));
	assert(!qfTest.isConnected(3, 7));

	int n = 1;
	while (n != 0) {
		std::cout << "Size of Vector: ";
		std::cin >> n;
		QF qf(n);

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
				qf.createUnion(rand() % qf.getSize(), rand() % qf.getSize());
			}

		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << duration << "ns total, average : " << duration / iterations << "ns." << std::endl << std::endl;

	}
	return 0;
}

