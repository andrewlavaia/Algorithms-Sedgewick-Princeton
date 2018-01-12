#include "WQUPC.h"

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