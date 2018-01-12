#include "QU.h"

QU::QU(int n) {
	m_size = n;

	for (int i = 0; i < n; i++) {
		m_id.push_back(i);
	}
}

int QU::findRoot(int i) {
	while (i != m_id[i]) {
		i = m_id[i];
	}
	return i;
}

void QU::createUnion(int p, int q) {
	int i = findRoot(p);
	int j = findRoot(q);

	m_id[i] = j;
}

bool QU::isConnected(int p, int q) {
	return findRoot(p) == findRoot(q);
}