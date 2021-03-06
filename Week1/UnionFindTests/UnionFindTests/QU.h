#pragma once

#include <vector>

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

