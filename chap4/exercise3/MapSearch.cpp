#include "MapSearch.h"

template <class M, typename V>
requires std::is_convertible_v<typename M::mapped_type, V>
typename M::key_type findKeyV(M mapObj, V value)
{
    for(auto element : mapObj)
        if(value == element.second)
            return element.first;
    return {};
};

template <class M, typename V>
requires std::is_convertible_v<typename M::mapped_type, V>
bool findKeyB(M mapObj, V value)
{
    for(auto element : mapObj)
        if(value == element.second)
            return true;
    return false;
};

template <class M, typename K>
requires std::is_convertible_v<typename M::key_type, K>
void printValue(M mapObj, std::string name, K key)
{
    try {
        auto value = mapObj.at(key);
        std::cout << name << " has " << key << " as a key\n"
                  << "and " << name << "[" << key << "]" << " is " << value << std::endl;
    } catch(const std::out_of_range& e) {
        std::cout << name << " does not have " << key << " as a key" << std::endl;
    }
}

template <class M, typename V>
requires std::is_convertible_v<typename M::mapped_type, V>
void printKey(M mapObj, std::string name, V value)
{
    bool isHaveValue = findKeyB(mapObj, value);
    std::cout << name << (isHaveValue ? " has " : " does not have ") << value << " as a value" << std::endl;
    if(isHaveValue)
        std::cout << "and " << name << "[?] == " << value << "\'s ? is " << findKeyV(mapObj, value) << std::endl; 
}

int main()
{
    using namespace std::literals;
    std::map<std::string, unsigned long> telephoneNumberBook{
      {"alice"s, 11111111111},
      {"bob"s, 22222222222},
      {"ava"s, 33333333333},
      {"harper"s, 44444444444}
    };
    
    std::cout << "Find value using key:\n";
    printValue(telephoneNumberBook, "telephoneNumberBook", "alice"s);
    printValue(telephoneNumberBook, "telephoneNumberBook", "anonymous"s);
    
    std::cout << "\nFind Key using value:\n";
    printKey(telephoneNumberBook, "telephoneNumberBook", 11111111111);
    printKey(telephoneNumberBook, "telephoneNumberBook", 55555555555);
    return 0;
}
