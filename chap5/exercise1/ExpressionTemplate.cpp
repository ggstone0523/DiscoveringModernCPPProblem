#include "ExpressionTemplate.h"

template <typename V1, typename V2>
auto operator+(V1&& x, V2&& y)
{
	return Vector_sum{std::forward<V1>(x), std::forward<V2>(y)};
}

int main()
{
	Vector<float> x = {1.0, 1.0, 2.0, -3.0},
		      y = {1.7, 1.7, 4.0, -6.0},
		      z = {4.1, 4.1, 2.6, 11.0},
		      w(4);
	w = x + y + z + Vector{2.0, 8.4, 9.1, 11.1};
	cout << w[0] << endl;
	cout << w[1] << endl;
	cout << w[2] << endl;
	cout << w[3] << endl;
	cout << typeid(x + y + z + Vector{2.0, 8.4, 9.1, 11.1}).name() << '\n' << endl;

	Vector<float> A = {1.0, 1.0, 1.0, 1.0};
	const Vector<float> B = {2.0, 2.0, 2.0, 2.0};
	Vector_sum C{A, B};
	const Vector_sum D{A, B};
	cout << "Vector<float> A is " << (is_vector_v<decltype(A)> ? "Vector" : "Not Vector") << endl;
	cout << "Const Vector<float> B is " << (is_vector_v<decltype(B)> ? "Vector" : "Not Vector") << endl;
	cout << "Vector_sum C{A, B} is " << (is_vector_v<decltype(C)> ? "Vector" : "Not Vector") << endl;
	cout << "const Vector_sum D{A, B} is " << (is_vector_v<decltype(D)> ? "Vector" : "Not Vector") << endl;
	cout << "3 is " << (is_vector_v<decltype(3)> ? "Vector" : "Not Vector") << "\n" << endl;
	
	cout << "A is " << (std::is_reference_v<decltype(A)> ? "Reference" : "Not Reference") << endl; 
	cout << "C is " << (std::is_reference_v<decltype(C)> ? "Reference" : "Not Reference") << endl; 
	typename FlipReferVec<decltype(A)>::type E = A;
	typename FlipReferVec<decltype(C)>::type F = C;
	cout << "Fliping non-reference type to reference type" << endl;
	cout << "E is " << (std::is_reference_v<decltype(E)> ? "Reference" : "Not Reference") << endl; 
	cout << "F is " << (std::is_reference_v<decltype(F)> ? "Reference" : "Not Reference") << endl; 
	typename FlipReferVec<decltype(E)>::type G = E;
	typename FlipReferVec<decltype(F)>::type H = F;
	cout << "Fliping reference type to non-reference type" << endl;
	cout << "G is " << (std::is_reference_v<decltype(G)> ? "Reference" : "Not Reference") << endl; 
	cout << "H is " << (std::is_reference_v<decltype(H)> ? "Reference" : "Not Reference") << endl; 

	return 0;
}
