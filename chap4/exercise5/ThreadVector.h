#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <cassert>
#include <mutex>
#include <chrono>

template <typename T>
void sumVector(T& sumv, const T& v, std::mutex& m);

template <typename T>
bool sameVectorElement(const T& sumv, const T& v);
