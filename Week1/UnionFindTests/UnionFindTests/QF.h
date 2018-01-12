#pragma once

#include <vector>

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
