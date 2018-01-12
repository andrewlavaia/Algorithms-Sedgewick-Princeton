#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>    // timer functions
#include <cstdlib>   // rand

class Percolation {
public:
	Percolation(int height, int width);
	void open(int row, int col);
	bool isOpen(int row, int col);
	bool isFull(int row, int col);
	int numberOfSites();
	bool percolates();
	int getHeight() { return m_rows; }
	int getWidth() { return m_cols; }
	void print();
	int findRoot(int i);
	void createUnion(int p, int q);
	bool isConnected(int p, int q);

private:
	int m_rows;
	int m_cols;
	std::vector<std::vector<int>> m_matrix;
	std::vector<int> m_unions;
	std::vector<int> m_nodeCount;
};

Percolation::Percolation(int height, int width) {
	m_rows = height;
	m_cols = width;
	std::vector<int> rowVec; 
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			rowVec.push_back(0);

			// create unique roots for top and bottom rows
			if (i == 0) {
				m_unions.push_back(0);
				m_nodeCount.push_back(width);
			}
			else if (i == height - 1) {
				m_unions.push_back(numberOfSites()-1);
				m_nodeCount.push_back(width);
			}
			else {
				m_unions.push_back((width*i) + j);
				m_nodeCount.push_back(1);
			}
		}
		m_matrix.push_back(rowVec);
	}
}

void Percolation::open(int row, int col) {
	m_matrix[row][col] = 1;

	// check top
	if (row - 1 >= 0) {
		if (isOpen(row - 1, col)) {
			createUnion((row * m_cols) + col, ((row - 1) * m_cols) + col);
		}
	}

	// check right
	if (col + 1 < m_cols) {
		if (isOpen(row, col + 1)) {
			createUnion((row * m_cols) + col, (row * m_cols) + col + 1);
		}
	}

	// check bottom
	if (row + 1 < m_rows) {
		if (isOpen(row + 1, col)) {
			createUnion((row * m_cols) + col, ((row + 1) * m_cols) + col);
		}
	}

	// check left
	if (col - 1 >= 0) {
		if (isOpen(row, col - 1)) {
			createUnion((row * m_cols) + col, (row * m_cols) + col - 1);
		}
	}
}

bool Percolation::isOpen(int row, int col) {
	return m_matrix[row][col];
}

bool Percolation::isFull(int row, int col) {
	return true;
}

int Percolation::numberOfSites() {
	return m_rows * m_cols;
}

bool Percolation::percolates() {
	return isConnected(0, numberOfSites()-1);
}

void Percolation::print() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			std::cout << m_unions[(i*m_cols) + j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

int Percolation::findRoot(int i) {
	while (i != m_unions[i]) {
		m_unions[i] = m_unions[m_unions[i]]; // skip a level and check grandparent 
		i = m_unions[i];
	}
	return i;
}

void Percolation::createUnion(int p, int q) {
	int i = findRoot(p);
	int j = findRoot(q);

	// if roots are the same, p and q are already in the same set
	if (i == j) {
		return;
	}

	// move tree with less nodes into tree with more nodes
	if (m_nodeCount[i] < m_nodeCount[j]) {
		m_unions[i] = j;
		m_nodeCount[j] += m_nodeCount[i];
	}
	else {
		m_unions[j] = i;
		m_nodeCount[i] += m_nodeCount[j];
	}
}

bool Percolation::isConnected(int p, int q) {
	return findRoot(p) == findRoot(q);
}

int main() {

	// unit tests
	Percolation percTest(10, 8);
	percTest.open(5, 5);
	percTest.open(4, 5);
	percTest.open(4, 6);
	percTest.open(4, 4);
	percTest.open(6, 8);
	percTest.open(7, 4);
	percTest.open(7, 7);
	assert(percTest.isOpen(5, 5));
	assert(!percTest.isOpen(5, 4));
	assert(percTest.numberOfSites() == 10 * 8);
	// percTest.print();

	int n = 1;
	while (n != 0) {
		int h;
		int w;
		std::cout << "height: ";
		std::cin >> h;
		std::cout << "width: ";
		std::cin >> w;
		
		Percolation perc(h, w);

		// Start Timer
		auto begin = std::chrono::high_resolution_clock::now();

		// Start Test
		for (int j = 0; j < 80; j++) {
			perc.open(rand() % perc.getHeight(), rand() % perc.getWidth());
		}
		
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		std::cout << "time elapsed: " << duration << "ns." << std::endl;

		
		perc.print();

		std::cout << "percolation: " << perc.percolates() << std::endl;
	
		std::cout << "enter 0 to exit, 1 to continue";
		std::cin >> n;
	
	}

	
	return 0;
}