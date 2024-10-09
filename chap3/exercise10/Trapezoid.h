#include <iostream>
#include <cmath>

// general programming method
struct exp3t
{
	template <typename T>
	auto operator() (T x) const
	{
		return std::exp(3.0 * x);
	}
};

struct sinonecost
{
	template <typename T>
	auto operator() (T x) const
	{
		return (x < 1) ? (std::sin(x)) : (std::cos(x));
	}
};

template <typename F, typename H>
class findiff
{
	public:
		findiff(F f, H h) : f{f}, h{h} {}
		
		template <typename T>
		auto operator() (T x) const
		{
			return (f(x + h) - f(x)) / h;
		}
	private:
		F f;
		H h;
};

template <typename F, typename T>
auto trapezoid(F f, const T& a, const T& b);

// inheritance method
struct functor_base
{
	virtual double operator() (double x) const = 0;
	virtual ~functor_base() = default;
};

class exp3tInherit
	: public functor_base
{
	public:
		virtual double operator() (double x) const override
		{
			return std::exp(3.0 * x);
		}
};

class sinonecostInherit
	: public functor_base
{
	public:
		virtual double operator() (double x) const override
		{
			return (x < 1) ? (std::sin(x)) : (std::cos(x));
		}
};

class findiffInherit
	: public functor_base
{
	public:
		findiffInherit(functor_base const& f, double h) : f{f}, h{h} {}
		
		virtual double operator() (double x) const override
		{
			return (f(x + h) - f(x)) / h;
		}
	private:
		functor_base const& f;
		double h;
};

double trapezoidInherit(functor_base const& f, double a, double b);
