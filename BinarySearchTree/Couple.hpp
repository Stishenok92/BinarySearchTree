#pragma once
#include <fstream>

template<typename Type1, typename Type2>
struct Couple
{
    Type1 first;
    Type2 second;
    Couple() = default;
    
    Couple<Type1, Type2>& makeCouple(const Type1& temp_first, const Type2& temp_second)
    {
        first = temp_first;
        second = temp_second;
        return *this;
    }
    
    bool operator==(const Couple<Type1, Type2>& couple) const
    {
        return first == couple.first ? true : false;
    }
    
    bool operator>(const Couple<Type1, Type2>& couple) const
    {
        return first > couple.first ? true : false;
    }
    
    bool operator<(const Couple<Type1, Type2>& couple) const
    {
        return first < couple.first ? true : false;
    }
    
    friend std::ostream& operator<<(std::ostream& out, Couple<Type1, Type2>& couple)
    {
        out << couple.second << "\n";
        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, Couple<Type1, Type2>& couple)
    {
        in >> couple.first >> couple.second;
        return in;
    }
};
