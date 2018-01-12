#pragma once

#include <vector>

class WQU
{
public:
	WQU(int n);
	int findRoot(int i);
	void createUnion(int p, int q);
	bool isConnected(int p, int q);
	int getSize() { return m_size; };

private:
	int m_size;
	std::vector<int> m_id;
	std::vector<int> m_nodeCount;
};
