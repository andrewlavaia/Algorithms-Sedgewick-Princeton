
#include <iostream>
#include <string>
#include <memory>

class Node {
public:
	std::string s;
	std::shared_ptr<Node> next;
};

class LinkedQueue {
public:
	bool isEmpty() {
		return (m_tail == nullptr);
	}

	void enqueue(std::string inputString) {
		if (!isEmpty()) {
			std::shared_ptr<Node> p = m_tail;
			m_tail = std::shared_ptr<Node>(new Node);
			m_tail->s = inputString;
			p->next = m_tail;
		}
		else {
			m_tail = std::shared_ptr<Node>(new Node);
			m_tail->s = inputString;
			m_head = m_tail;

		}

	}

	std::string dequeue() {
		if (!isEmpty()) {
			std::shared_ptr<Node> p = m_head;

			if (m_head == m_tail) {
				m_head = nullptr;
				m_tail = nullptr;
			}
			else {
				m_head = m_head->next;
			}
			return p->s;

		}
		else {
			return "can't dequeue - empty";
		}

	}

private:
	std::shared_ptr<Node> m_head = nullptr;
	std::shared_ptr<Node> m_tail = nullptr;
};


int main() {

	LinkedQueue linkQueue;
	linkQueue.enqueue("go1");
	std::cout << linkQueue.dequeue() << std::endl;
	linkQueue.enqueue("go2");
	linkQueue.enqueue("go3");
	std::cout << linkQueue.isEmpty() << std::endl;
	std::cout << linkQueue.dequeue() << std::endl;
	linkQueue.enqueue("go4");
	std::cout << linkQueue.dequeue() << std::endl;
	std::cout << linkQueue.isEmpty() << std::endl;
	std::cout << linkQueue.dequeue() << std::endl;
	linkQueue.enqueue("go5");


	int stackSize = 0;
	std::cout << "enter 0 to exit" << std::endl;
	std::cin >> stackSize;
	while (stackSize != 0) {

	}
	return 0;
}