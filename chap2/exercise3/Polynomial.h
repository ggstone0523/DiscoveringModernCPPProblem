#include <iostream>
#include <initializer_list>
#include <valarray>

class polynomial
{
	public:
		polynomial(unsigned degree) 
			: degree{degree}, co{std::valarray<double>(degree + 1)} {};
		
		polynomial(std::initializer_list<double> cos)
			: degree{(unsigned int)cos.size() - 1}, co{std::valarray<double>(cos)} {};
		
		polynomial& operator=(std::initializer_list<double> cos)
		{ 
			degree = (unsigned int)cos.size() - 1;
			co = std::valarray<double>(cos);

			return *this;
		};

		polynomial& operator=(polynomial&& p) noexcept
		{
			std::cout << "Start operation of move assignment operator!" << std::endl;
			degree = p.degree;
			co = p.co;
			p.co = std::valarray<double>(0);
			p.degree = 0;
			std::cout << "Complete operation of move assignment operator!" << std::endl;

			return *this;
		};
		
		polynomial& operator=(polynomial& p) = default;

		friend std::ostream& operator<<(std::ostream& os, const polynomial& p)
		{
			os << p.co[0] << "x^" << p.degree;
			for(unsigned i = 1; i < p.degree; i++) {
				if(p.co[i] == 0)
					continue;
				os << " + " << p.co[i] << "x^" << p.degree - i;
			}
			if(p.co[p.degree] != 0)
				os << " + " << p.co[p.degree];
			return os;
		};

		~polynomial() = default;
	private:
		std::valarray<double> co;
		unsigned degree;
};

polynomial makeQuadFunc(double c2, double c1, double c0);
