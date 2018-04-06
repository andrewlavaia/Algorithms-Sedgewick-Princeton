#pragma once

#include <vector>
#include <cassert>

class MergeSort
{
public:
	MergeSort(int n, int range);
	void sort();
	void print();

private:
	void merge(int lo, int mid, int hi);
	void recursiveSort(int lo, int hi);
	bool less(int p, int q);

	std::vector<int> m_data;
	std::vector<int> m_aux;
	int m_size;
};