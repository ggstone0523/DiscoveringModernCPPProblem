#include "Stack.h"

void testStack()
{
	std::cout << "\ntestStack() start!\n" << std::endl;

	std::string strs[] = {
		"Apple", "Banana", "Chocolate", "Diamond", "Exercise",
		"Firefighter", "Guitar", "House", "Iron", "Jarket"
	};

	stack<std::string, 10> s;
	
	for(auto i : strs)
	{
		s.push(i);
	}

	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Stack clear..." << std::endl;
	s.clear();
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "\nPush elements to Stack..." << std::endl;
	for(auto i : strs)
	{
		s.push(i);
	}
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "Pop elements from Stack..." << std::endl;
	while(!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "\ntestStack() end!\n" << std::endl;
}

void testBoolStack()
{
	std::cout << "\ntestBoolStack() start!\n" << std::endl;
	
	bool bools[] = {true, true, false, false, true, false, false, false, true, true};
	stack<bool> s;
	
	for(auto i : bools)
	{
		s.push(i);
	}

	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Stack clear..." << std::endl;
	s.clear();
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "\nPush elements to Stack..." << std::endl;
	for(auto i : bools)
	{
		s.push(i);
	}
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "Pop elements from Stack..." << std::endl;
	while(not s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "\ntestBoolStack() end!\n" << std::endl;
}

int main()
{
	testStack();
	std::cout << "--------------------------------------------------------------" << std::endl;
	testBoolStack();
	return 0;
}
