#include "BoolStack.h"

int main()
{
	bool bools[] = {true, true, false, false, true, false, false, false, true, true};
	const int length = 10;
	stack<bool, length> s;

	for(int i = 0; i < length; i++)
	{
		s.push(bools[i]);
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
	for(int i = 0; i < length; i++)
	{
		s.push(bools[i]);
	}
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;
	
	std::cout << "Pop elements from Stack..." << std::endl;
	for(int i = 0; i < length; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << "Current size of stack is " << s.size() << std::endl;
	std::cout << "Is This full? " << (s.full() ? "Yes" : "No") << std::endl;
	std::cout << "Is This empty? " << (s.empty() ? "Yes" : "No") << std::endl;

	return 0;
}
