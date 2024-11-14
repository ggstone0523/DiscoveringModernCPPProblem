#include "AsyncVector.h"

template <typename T>
void sumVector(T& sumv, const T& v1, const T& v2, int start, int end, std::mutex& m)
{
	int size = sumv.size();
	std::cout << start << " " << end << std::endl;
	assert(size == v1.size() && size == v2.size());
	for(int i = start; i < end; ++i) {
		m.lock();
		if(i < size)
			sumv[i] += v1[i];
		else
			sumv[i - size] += v2[i - size];
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
	
	const int num_threads = std::thread::hardware_concurrency();
	std::cout << num_threads << " threads available.\n";
	std::vector<int> threadsWork;
	for(int i = 0; i < num_threads; ++i)
		threadsWork.push_back(0);
	for(int i = 0, size = sumv.size() * 2; i < size; ++i)
		threadsWork[i % num_threads]++;
	int beforeValue = 0;
	for(int i = 0; i < num_threads; ++i) {
		threadsWork[i] += beforeValue;
		beforeValue = threadsWork[i];
	}

	std::mutex m;
	std::vector<std::future<void>> vf;
	beforeValue = 0;
	time_point<steady_clock> start = steady_clock::now();
	for(int i = 0; i < num_threads; ++i) {
		vf.emplace_back(std::async(std::launch::deferred, 
			[&v1, &v2, &sumv, &m, &threadsWork, i, beforeValue](){ 
			sumVector(sumv, v1, v2, beforeValue, threadsWork[i], m);
		}));
		beforeValue = threadsWork[i];
	}
	for(int i = 0; i < num_threads; ++i)
		vf[i].wait();
	auto end = steady_clock::now();
	std::cout << "The calculation took " << duration_cast<microseconds>(end - start).count()
		  << " micros." << std::endl;
	std::cout << "result is " << (sameVectorElement(sumv, v1) ? "true" : "false") << std::endl;
	return 0;
}
