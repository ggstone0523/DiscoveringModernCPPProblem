#include <iostream>
#include <initializer_list>
#include <cassert>
#include <valarray>

class polynomial
{
	public:
		polynomial(unsigned degree) 
			: degree{degree}, co{std::valarray<double>(degree + 1)} {};
		
		polynomial(unsigned degree, std::valarray<double> co) 
			: degree{degree}, co{co} {};
		
		polynomial& operator=(std::valarray<double> cos)
		{
			assert((degree + 1) == cos.size());
			for(unsigned i = 0; i <= degree; i++)
				co[degree- i] = cos[i];
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
		
		polynomial& operator=(polynomial& p)
		{
			degree = p.degree;
			std::valarray<double> temp(degree + 1);
			for(unsigned i = 0; i <= degree; i++)
				temp[i] = p.co[i];
			co = temp;

			return *this;
		};

		polynomial operator+(const polynomial& p)
		{
			unsigned allDegree = p.degree > degree ? p.degree : degree;
			std::valarray<double> cop(allDegree + 1);

			if(p.degree == degree)
				cop = co + p.co;
			else {
				std::valarray<double> temp(allDegree + 1);
				if(allDegree == p.degree) {
					for(unsigned i = allDegree; i >= 1; i--)
						if(i > degree)
							temp[i] = 0;
						else
							temp[i] = co[i];
					if(degree >= 0)
						temp[0] = co[0];
					cop = temp + p.co;
				} else {
					for(unsigned i = allDegree; i >= 1; i--)
						if(i > p.degree)
							temp[i] = 0;
						else
							temp[i] = p.co[i];
					if(p.degree >= 0)
						temp[0] = p.co[0];
					cop = co + temp;
				}
			}
			return polynomial(allDegree, cop);
		};
		
		polynomial operator-(const polynomial& p)
		{
			unsigned allDegree = p.degree > degree ? p.degree : degree;
			std::valarray<double> cop(allDegree + 1);

			if(p.degree == degree)
				cop = co - p.co;
			else {
				std::valarray<double> temp(allDegree + 1);
				if(allDegree == p.degree) {
					for(unsigned i = allDegree; i >= 1; i--)
						if(i > degree)
							temp[i] = 0;
						else
							temp[i] = co[i];
					if(degree >= 0)
						temp[0] = co[0];
					cop = temp - p.co;
				} else {
					for(unsigned i = allDegree; i >= 1; i--)
						if(i > p.degree)
							temp[i] = 0;
						else
							temp[i] = p.co[i];
					if(p.degree >= 0)
						temp[0] = p.co[0];
					cop = co - temp;
				}
			}
			return polynomial(allDegree, cop);
		};

		friend std::ostream& operator<<(std::ostream& os, const polynomial& p)
		{
			os << p.co[p.degree] << "x^" << p.degree;
			for(unsigned i = p.degree - 1; i >= 1; i--) {
				if(p.co[i] == 0)
					continue;
				os << " + " << p.co[i] << "x^" << i;
			}
			if(p.co[0] != 0)
				os << " + " << p.co[0];
			return os;
		};

		~polynomial() = default;
	private:
		std::valarray<double> co;
		unsigned degree;

};
