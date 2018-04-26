#include "hashtable.h"

HashTable::HashTable(int M) : M(M) {
	for (auto i = 0; i < M; ++i)
		st.push_back(nullptr);
}

HashTable::Node::Node(std::string key, int val) : key(key), val(val) {

}

void HashTable::put(std::string key, int val) {
	int i = hash(key);
	if (st[i] == nullptr) {
		st[i] = std::make_shared<Node>(key, val);
	}
}

int HashTable::getVal(std::string key) {

	return 0;
}

int HashTable::hash(std::string key) {

	return 0;
}