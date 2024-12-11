#include <iostream>
#include <numeric>
#include <cassert>

template <typename N, typename D>
class rational
{
	public:
		rational(N inputN = 0, D inputD = 1) : numerator{inputN}, denominator{inputD}
		{
			assert(inputD != 0);
			if(inputD < 0) {
				numerator *= -1;
				denominator *= -1;
			}
			setIrrFrac();
		};

		template <typename ON, typename OD>
		rational(rational<ON,OD>& r) : numerator{(N)(r.getN())}, denominator{(D)(r.getD())} {};
		
		template <typename ON, typename OD>
		rational(rational<ON,OD>&& r) noexcept : numerator{(N)(r.getN())}, denominator{(D)(r.getD())}
		{
			r.setN(0);
			r.setD(1);	
		};

		template <typename ON, typename OD>
		rational& operator=(const rational<ON, OD>& r)
		{
			numerator = (N)(r.getN());
			denominator = (D)(r.getD());

			return *this;
		};
		
		template <typename ON, typename OD>
		rational& operator=(rational<ON, OD>&& r) noexcept
		{
			numerator = (N)r.getN();
			denominator = (D)r.getD();
			r.setN(0);
			r.setD(1);

			return *this;
		};

		template <typename ON, typename OD>
		auto operator+(const rational<ON, OD>& r) 
		-> rational<decltype(N{1} * OD{1} + ON{1} * D{1}), decltype(D{1} * OD{1})>
		{
			if(denominator == r.getD())
				return rational(numerator + r.getN(), denominator);
			else
				return rational((numerator * r.getD()) + \
						( r.getN() * denominator),
						denominator * r.getD());
		};
		
		template <typename ON, typename OD>
		auto operator-(const rational<ON, OD>& r) 
		-> rational<decltype(N{1} * OD{1} - ON{1} * D{1}), decltype(D{1} * OD{1})>
		{
			if(denominator == r.getD())
				return rational(numerator - r.getN(), denominator);
			else
				return rational((numerator * r.getD()) - \
						( r.getN() * denominator),
						denominator * r.getD());
		};
		
		template <typename ON, typename OD>
		auto operator*(const rational<ON, OD>& r) 
		-> rational<decltype(N{1} * ON{1}), decltype(D{1} * OD{1})>
		{
			return rational(numerator * r.getN(), denominator * r.getD());
		};
		
		template <typename ON, typename OD>
		auto operator/(const rational<ON, OD>& r) 
		-> rational<decltype(N{1} * OD{1}), decltype(D{1} * ON{1})>
		{
			return rational(numerator * r.getD(), denominator * r.getN());
		};
		
		template <typename ON, typename OD>
		rational& operator+=(const rational<ON, OD>& r)
		{
			if(denominator == r.getD())
				numerator = (N)(numerator + r.getN());
			else {
				numerator = (N)(numerator * r.getD() + r.getN() * denominator);
				denominator = (D)(denominator * r.getD());
			}
			setIrrFrac();
			return *this;
		};
		
		template <typename ON, typename OD>
		rational& operator-=(const rational<ON, OD>& r)
		{
			if(denominator == r.getD())
				numerator = (N)(numerator - r.getN());
			else {
				numerator = (N)(numerator * r.getD() - r.getN() * denominator);
				denominator = (D)(denominator * r.getD());
			}
			setIrrFrac();
			return *this;
		};
		
		template <typename ON, typename OD>
		rational& operator*=(const rational<ON, OD>& r)
		{
			numerator = (N)(numerator * r.getN());
			denominator = (D)(denominator * r.getD());
			setIrrFrac();
			return *this;
		};
		
		template <typename ON, typename OD>
		rational& operator/=(const rational<ON, OD>& r)
		{
			numerator = (N)(numerator * r.getD());
			denominator = (D)(denominator * r.getN());
			setIrrFrac();
			return *this;
		};

		friend std::ostream& operator<<(std::ostream& os, const rational& r)
		{
			if(r.numerator != 0)
				return os << "(" << r.numerator << " / " << r.denominator << ")";
			else
				return os << "(0)";
		};

		N getN() { return numerator; };
		
		D getD() { return denominator; };
		
		const N getN() const { return numerator; };
		
		const D getD() const { return denominator; };
		
		void setN(N newN) { numerator = newN; };
		
		void setD(D newD) { denominator = newD; };

		~rational() = default;
	private:
		void setIrrFrac()
		{
			if(numerator != 0) {
				int ndGcd = std::gcd(numerator, denominator);
				numerator = numerator / ndGcd;
				denominator = denominator / ndGcd;
			}
		};
		
		N numerator;
		D denominator;
};
