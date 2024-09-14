#include <iostream>
#include <initializer_list>
#include <valarray>
#include <cmath>

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
			degree = p.degree;
			co = p.co;
			p.co = std::valarray<double>(0);
			p.degree = 0;

			return *this;
		};
		
		polynomial& operator=(polynomial& p) = default;

		polynomial operator+(const polynomial& p)
		{
			unsigned allDegree = p.degree > degree ? p.degree : degree;
			std::valarray<double> cop(allDegree + 1);

			if(p.degree == degree)
				cop = co + p.co;
			else {
				std::valarray<double> temp(allDegree + 1);
				double diffSizeOfPdd = abs(p.degree - degree);
				if(allDegree == p.degree) {
					for(unsigned i = 0; i <= allDegree; i++)
						if(i < diffSizeOfPdd)
							temp[i] = 0;
						else
							temp[i] = co[i - diffSizeOfPdd];
					cop = temp + p.co;
				} else {
					for(unsigned i = 0; i <= allDegree; i++)
						if(i < diffSizeOfPdd)
							temp[i] = 0;
						else
							temp[i] = p.co[i - diffSizeOfPdd];
					cop = co + temp;
				}
			}
			return polynomial(cop);
		};
		
		polynomial operator-(const polynomial& p)
		{
			unsigned allDegree = p.degree > degree ? p.degree : degree;
			std::valarray<double> cop(allDegree + 1);

			if(p.degree == degree)
				cop = co - p.co;
			else {
				std::valarray<double> temp(allDegree + 1);
				double diffSizeOfPdd = abs(p.degree - degree);
				if(allDegree == p.degree) {
					for(unsigned i = 0; i <= allDegree; i++)
						if(i < diffSizeOfPdd)
							temp[i] = 0;
						else
							temp[i] = co[i - diffSizeOfPdd];
					cop = temp - p.co;
				} else {
					for(unsigned i = 0; i <= allDegree; i++)
						if(i < diffSizeOfPdd)
							temp[i] = 0;
						else
							temp[i] = p.co[i - diffSizeOfPdd];
					cop = co - temp;
				}
			}
			return polynomial(cop);
		};

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
		polynomial(std::valarray<double> cop)
			: degree{(unsigned)cop.size() - 1}, co{cop} {};

		std::valarray<double> co;
		unsigned degree;
};
