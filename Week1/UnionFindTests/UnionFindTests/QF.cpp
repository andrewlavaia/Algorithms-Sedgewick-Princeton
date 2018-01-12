#include "QF.h"

QF::QF(int n) {
	m_size = n;

	for (int i = 0; i < n; i++) {
		m_id.push_back(i);
	}
}

void QF::createUnion(int p, int q) {
	if (m_id[p] != m_id[q]) {
		int pval = m_id[p];
		int qval = m_id[q];

		for (int i = 0; i < m_size; i++) {
			if (m_id[i] == pval) {
				m_id[i] = qval;
			}
		}
	}
}

bool QF::isConnected(int p, int q) {
	return m_id[p] == m_id[q];
}
