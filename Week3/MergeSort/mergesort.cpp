#include "mergesort.h"

#include <iostream>

MergeSort::MergeSort(int n, int range) {
	for (int i = 0; i < n; i++) {
		m_data.push_back(rand() % range);
		m_aux.push_back(0); // allocate same space
	}

	m_size = n;
}

void MergeSort::sort() {
	recursiveSort(0, m_size - 1);
}

void MergeSort::print() {
	for (auto i = 0; i < m_data.size(); i++) {
		std::cout << m_data[i] << std::endl;
	}
	std::cout << "------------" << std::endl;
}


// merges two consecutive sorted subarrays of m_data
void MergeSort::merge(int lo, int mid, int hi) {
	int i = lo;					// starting point of first subarray
	int j = mid + 1;    // starting point of second subarray

	// copy values into aux array
	for (int k = lo; k <= hi; k++) {
		m_aux[k] = m_data[k];
	}

	for (int k = lo; k <= hi; k++) {
		if (i > mid) {		// first subarray exhausted, must be in second
			m_data[k] = m_aux[j]; 
			j++;
		}
		else if (j > hi) {	// second subarray exhausted, must be in first 
			m_data[k] = m_aux[i];  
			i++;
		} 
		else if (less(m_aux[j], m_aux[i])) { // item in second subarray is less than item in first
			m_data[k] = m_aux[j];
			j++;
		}
		else {	// item in first subarray is less than or equal to item in second
			m_data[k] = m_aux[i];
			i++;
		}

	}
}

// recursively sorts m_data by splitting it into smaller subarrays
void MergeSort::recursiveSort(int lo, int hi) {
	if (hi <= lo) {
		return;
	}

	int mid = lo + ((hi - lo) / 2);
	recursiveSort(lo, mid);			// sort left half
	recursiveSort(mid + 1, hi); // sort right half
	merge(lo, mid, hi);
}

bool MergeSort::less(int p, int q) {
	return p < q;
}