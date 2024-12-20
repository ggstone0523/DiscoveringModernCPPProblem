class my_vector {
	public:
		using value_type = double;

		my_vector(int n);

		my_vector(my_vector const &);

		template <typename Vector>
		my_vector(Vector const&);

		my_vector& operator=(my_vector const& v);

		template <typename Vector>
		my_vector& operator=(Vector const& v);

		value_type& operator()(int i);

		int size() const;

		value_type operator()(int i) const;
}

template <typename Scalar, typename Vector>
class scalar_times_vector_expression
{};

template <typename Scalar, typename Vector>
scalar_times_vector_expressions<Scalar, Vector>
operator*(Scalar const& s, Vector const& v)
{
	return scalar_times_vector_expressions<Scalar, Vector>(s, v);
}

int main()
{
	my_vector v(5);

	my_vector w(5);
	w = 5.0 * v;

	w = 5.0 * (7.0 * v);
	w = v + 7.0 * v;

	return 0;
}
