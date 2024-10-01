#include "Iter.h"

int main()
{
	vector<int> a(5);
	std::cout << "Insert Data..." << std::endl;
	for(int i = 4; i >= 0; i--)
		a[4 - i] = i;
	for(int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;
	std::cout << "Sort..." << std::endl;
	std::sort(a.begin(), a.end());
	for(int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;
	
	std::cout << "Reset..." << std::endl;
	for(int i = 4; i >= 0; i--)
		a[4 - i] = i;
	for(int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;
	
	std::cout << "Sort again..." << std::endl;
	std::sort(a.begin(), a.end());
	for(int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

	std::cout << "Check Over and Underflow when using +, - and vector size is 5" << std::endl;
	std::cout << " +6: " 
		  << ((a.begin() + 6).isOverflow() ? "Overflow" : "Not overflow")
		  << std::endl;
	std::cout << " -1: " 
		  << ((a.begin() - 1).isUnderflow() ? "Underflow" : "Not underflow")
		  << std::endl;
	std::cout << " +3: " 
		  << ((a.begin() + 3).isOverflow() ? "Overflow" : "Not overflow")
		  << std::endl;
	std::cout << " +3: " 
		  << ((a.begin() + 3).isUnderflow() ? "Underflow" : "Not underflow")
		  << std::endl;

	std::cout << "Check Over and Underflow when using +=, -= and vector size is 5" << std::endl;
	std::cout << "+=6: " 
		  << ((a.begin() += 6).isOverflow() ? "Overflow" : "Not overflow")
		  << std::endl;
	std::cout << "-=1: " 
		  << ((a.begin() -= 1).isUnderflow() ? "Underflow" : "Not underflow")
		  << std::endl;
	std::cout << "+=3: " 
		  << ((a.begin() += 3).isOverflow() ? "Overflow" : "Not overflow")
		  << std::endl;
	std::cout << "+=3: " 
		  << ((a.begin() += 3).isUnderflow() ? "Underflow" : "Not underflow")
		  << std::endl;
	
	vector<int> b(5);
	std::cout << "Are a's vector_iterator and b's vector_iterator the same? "
		  << ((a.begin() == b.begin()) ? "Yes" : "No") << std::endl;
	std::cout << "Are a's vector_iterator and a's vector_iterator the same? "
		  << ((a.begin() == a.begin()) ? "Yes" : "No") << std::endl;

	return 0;
}
