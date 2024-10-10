#include <iostream>
#include <cmath>

struct cosxpsx
{
	double operator() (double x) const
	{
		return std::cos(x) + x * x;
	}
};

struct two
{
	double operator() (double x) const
	{
		return 2;
	}
};

template <unsigned N, typename F, typename T>
class findiff
{
	using prev_findiff = findiff<N - 1, F, T>;
	public:
		findiff(F f, T h) : fp{f, h}, h{h} {}

		T operator() (T x) 
		{
			return N & 1 ? (fp(x + h) - fp(x)) / h
			             : (fp(x) - fp(x - h)) / h;
		}
	private:
		T h;
		prev_findiff fp;
};

template<typename F, typename T>
class findiff<1, F, T>
{
	public:
		findiff(const F& f, const T& h) : f{f}, h{h} {}

		T operator() (T x) const
		{
			return (f(x + h) - f(x)) / h;
		}
	private:
		T h;
		const F& f;
};

template <unsigned N, typename F, typename T>
findiff<N, F, T>
findiff_f(const F& f, const T& h);
