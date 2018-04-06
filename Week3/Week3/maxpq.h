#pragma once

#include <iostream>
#include <vector>
#include <cassert>

/* Priority Queue
 *  Can insert, retrieve, or delete the maximum item
 *  in an array in nlog(n) time.
 *  Uses a binary heap data structure
 */
class MaxPQ
{
public:
	MaxPQ();
	void insert(int val);
	void deleteMax();
	int getSize();
	void print();

private:	
	void swim(int k);
	void sink(int k);
	bool less(int p, int q);
	void swap(int p, int q);

	std::vector<int> m_data;
	int m_size;
};