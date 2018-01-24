
#include <iostream>
#include <string>

class ArrayStack {
public:
	bool isEmpty() {
		if (m_index == 0)
			return true;
		else
			return false;
	}

	void push(std::string s) {
		m_stack[m_index] = s;
		m_index++;
	}

	std::string pop() {
		std::string s = m_stack[m_index - 1];
		m_stack[m_index - 1] = "";
		m_index--;
		return s;
	}

private:
	int m_index = 0;
	std::string m_stack[10];
};

int main() {

	ArrayStack arrStack;
	arrStack.push("go1");
	std::cout << arrStack.pop() << std::endl;
	arrStack.push("go2");
	arrStack.push("go3");
	std::cout << arrStack.pop() << std::endl;
	std::cout << arrStack.pop() << std::endl;
	
	int stackSize = 0;
	std::cout << "enter 0 to exit" << std::endl;
	std::cin >> stackSize;
	while (stackSize != 0) {
	
		
	}

	return 0;
}