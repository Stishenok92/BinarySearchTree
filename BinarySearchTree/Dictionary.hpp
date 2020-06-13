#pragma once
#include<iostream>
#include<string>

struct Dictionary
{
    std::string english;
    std::string russian;
    size_t counter = 0;
    
    size_t getCounter() const { return counter; }
    
    void setEnglish(std::string eng)
    {
        english = eng;
    }
    
    void setRussian(std::string rus)
    {
        russian = rus;
    }
    
    std::string translateRus()
    {
//        ++counter;
        return russian;
    }
    std::string translateEng()
    {
//        ++counter;
        return english;
    }
    
    friend std::ostream& operator<<(std::ostream& out, Dictionary& word)
    {
//        word.counter++;
        out << word.english << " " << word.russian << " " << word.counter;
        return out;
    }
    
    friend std::istream& operator>>(std::istream& in, Dictionary& word)
    {
        in >> word.english >> word.russian >> word.counter;
        return in;
    }
};
