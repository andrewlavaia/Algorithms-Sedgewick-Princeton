#include "maxpq.h"

MaxPQ::MaxPQ() {
	m_data.push_back(0); // start index at 1 to make future arithmetic easier
	m_size = 0;
}

void MaxPQ::insert(int val) {
	m_data.push_back(val);
	m_size++;
	swim(m_size); // size = last index
}

void MaxPQ::deleteMax() {
	assert(getSize() > 0);
	swap(1, m_size); 
	m_data.pop_back();
	m_size--;
	sink(1);
}

int MaxPQ::getSize() {
	return m_size;
}

void MaxPQ::print() {
	for (auto i = 1; i < m_data.size(); i++) {
		std::cout << i << " : " << m_data[i] << std::endl;
	}
	std::cout << std::endl;
}

void MaxPQ::swim(int k) {
	if (k == 1) { // top node
		return;
	}
	int parent = k / 2;
	if (less(parent, k)) {
		swap(k, parent);
		swim(parent);
	}
}

void MaxPQ::sink(int k) {
	int child = k * 2;
	if (child > m_size) { // no more children
		return;
	}
	else if (child + 1 > m_size) { // only one child
		swap(k, child);
	}
	else if (less(child + 1, child)) { // first child is larger
		swap(k, child);
		sink(child);
	}
	else if(less(child, child + 1)) { // second child is larger
		swap(k, child + 1);
		sink(child + 1);
	}
}

bool MaxPQ::less(int p, int q) {
	return m_data[p] < m_data[q];
}

void MaxPQ::swap(int p, int q) {
	int temp = m_data[p];
	m_data[p] = m_data[q];
	m_data[q] = temp;
}