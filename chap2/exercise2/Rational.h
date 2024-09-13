#include <iostream>
#include <numeric>
#include <cassert>

class rational 
{
	public:
		rational(int inputN, int inputD = 1) : numerator{inputN}, denominator{inputD}
		{
			assert(inputD > 0);
			setIrrFrac();
		};

		rational& operator=(const rational& r)
		{
			numerator = r.numerator;
			denominator = r.denominator;

			return *this;
		};
		
		rational& operator=(rational&& r) noexcept
		{
			numerator = r.numerator;
			denominator = r.denominator;
			r.numerator = 0;
			r.denominator = 1;

			return *this;
		};

		rational operator+(const rational& r)
		{
			if(denominator == r.denominator)
				return rational(numerator + r.numerator, denominator);
			else
				return rational((numerator * r.denominator) + \
						( r.numerator * denominator),
						denominator * r.denominator);
		};
		
		rational operator-(const rational& r)
		{
			if(denominator == r.denominator)
				return rational(numerator - r.numerator, denominator);
			else
				return rational((numerator * r.denominator) - \
						( r.numerator * denominator),
						denominator * r.denominator);
		};
		
		rational operator*(const rational& r)
		{
			return rational(numerator * r.numerator, denominator * r.denominator);
		};
		
		rational operator/(const rational& r)
		{
			return rational(numerator * r.denominator, denominator * r.numerator);
		};
		
		rational& operator+=(const rational& r)
		{
			if(denominator == r.denominator)
				numerator = numerator + r.numerator;
			else {
				numerator = numerator * r.denominator + r.numerator * denominator;
				denominator = denominator * r.denominator;
			}
			setIrrFrac();
			return *this;
		};
		
		rational& operator-=(const rational& r)
		{
			if(denominator == r.denominator)
				numerator = numerator - r.numerator;
			else {
				numerator = numerator * r.denominator - r.numerator * denominator;
				denominator = denominator * r.denominator;
			}
			setIrrFrac();
			return *this;
		};
		
		rational& operator*=(const rational& r)
		{
			numerator = numerator * r.numerator;
			denominator = denominator * r.denominator;
			setIrrFrac();
			return *this;
		};
		
		rational& operator/=(const rational& r)
		{
			numerator = numerator * r.denominator;
			denominator = denominator * r.numerator;
			setIrrFrac();
			return *this;
		};

		friend std::ostream& operator<<(std::ostream& os, const rational& r)
		{
			return os << "(" << r.numerator << " / " << r.denominator << ")";
		};

		~rational() = default;
	private:
		void setIrrFrac()
		{
			int ndGcd = std::gcd(numerator, denominator);
			numerator = numerator / ndGcd;
			denominator = denominator / ndGcd;
		};
		
		int numerator;
		int denominator;
};
