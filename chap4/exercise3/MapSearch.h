#include <iostream>
#include <map>
#include <string>

template <class M, typename V>
requires std::is_convertible_v<typename M::mapped_type, V>
typename M::key_type findKeyV(M mapObj, V value);

template <class M, typename V>
requires std::is_convertible_v<typename M::mapped_type, V>
bool findKeyB(M mapObj, V value);

template <class M, typename K>
requires std::is_convertible_v<typename M::key_type, K>
void printValue(M mapObj, std::string name, K key);

template <class M, typename V>
requires std::is_convertible_v<typename M::mapped_type, V>
void printKey(M mapObj, std::string name, V value);
