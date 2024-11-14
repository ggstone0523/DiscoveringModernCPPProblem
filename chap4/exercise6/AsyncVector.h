#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <mutex>
#include <chrono>
#include <future>

template <typename T>
void sumVector(T& sumv, const T& v1, const T& v2, int start, int end, std::mutex& m);

template <typename T>
bool sameVectorElement(const T& sumv, const T& v);
