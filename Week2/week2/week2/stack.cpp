
#include <iostream>
#include <string>
#include <memory>

class ArrayStack {
public:
	bool isEmpty() {
		return (m_index == 0);
	}

	void push(std::string s) {
		m_stack[m_index] = s;
		m_index++;
	}

	std::string pop() {
		if (!isEmpty()) {
			std::string s = m_stack[m_index - 1];
			m_stack[m_index - 1] = "";
			m_index--;
			return s;
		}
		else {
			return "can't pop - empty";
		}

	}

private:
	int m_index = 0;
	std::string m_stack[10];
};

class Node {
public:
	std::string s;
	std::shared_ptr<Node> next;
};

class LinkedStack {
public:
	bool isEmpty() {
		return (m_first == nullptr);
	}

	void push(std::string s) {
		std::shared_ptr<Node> temp = m_first;
		m_first = std::shared_ptr<Node>(new Node);
		m_first->s = s;
		m_first->next = temp;
	}

	std::string pop() {
		if (!isEmpty()) {
			std::string temp = m_first->s;
			m_first = m_first->next;
			return temp;
		}
		else {
			return "can't pop - empty";
		}
	}

private:
	std::shared_ptr<Node> m_first;
};

int main() {

	ArrayStack arrStack;
	arrStack.push("go1");
	std::cout << arrStack.pop() << std::endl;
	arrStack.push("go2");
	arrStack.push("go3");
	std::cout << arrStack.pop() << std::endl;
	std::cout << arrStack.pop() << std::endl;
	std::cout << arrStack.isEmpty() << std::endl;
	std::cout << arrStack.pop() << std::endl;
	
	LinkedStack linkStack;
	
	linkStack.push("go1");
	std::cout << linkStack.pop() << std::endl;
	linkStack.push("go2");
	linkStack.push("go3");
	std::cout << linkStack.isEmpty() << std::endl;
	std::cout << linkStack.pop() << std::endl;
	std::cout << linkStack.pop() << std::endl;
	std::cout << linkStack.isEmpty() << std::endl;
	std::cout << linkStack.pop() << std::endl;
	
	int stackSize = 0;
	std::cout << "enter 0 to exit" << std::endl;
	std::cin >> stackSize;
	while (stackSize != 0) {
	
		
	}

	return 0;
}