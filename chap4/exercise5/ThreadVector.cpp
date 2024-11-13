#include "ThreadVector.h"

template <typename T>
void sumVector(T& sumv, const T& v, std::mutex& m)
{
	assert(sumv.size() == v.size());
	int sizev = sumv.size();
	for(int i = 0; i < sizev; ++i) {
		m.lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		sumv[i] += v[i];
		m.unlock();
	}
}

template <typename T>
bool sameVectorElement(const T& sumv, const T& v)
{
	assert(sumv.size() == v.size());
	int sizev = v.size();
	for(int i = 0; i < sizev; ++i)
		if(sumv[i] != (v[i] * 2))
			return false;
	return true;
}

int main()
{
	using namespace std::chrono;
	std::vector<int> v1, v2, sumv;

	for(int i = 1; i <= 1000; i++) {
		v1.push_back(i);
		v2.push_back(i);
		sumv.push_back(0);
	}
	
	std::mutex m;
	time_point<steady_clock> start = steady_clock::now();
	std::thread t1([&v1, &sumv, &m](){ sumVector(sumv, v1, m); });
	std::thread t2([&v2, &sumv, &m](){ sumVector(sumv, v2, m); });
	t1.join();
	t2.join();
	auto end = steady_clock::now();
	std::cout << "The calculation took " << duration_cast<seconds>(end - start).count()
		  << " seconds." << std::endl;

	std::cout << "result is " << (sameVectorElement(sumv, v1) ? "true" : "false") << std::endl;

	return 0;
}
