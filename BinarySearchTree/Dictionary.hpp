#pragma once
#include<iostream>
#include<string>
#include<iomanip>

struct Dictionary
{
    std::string english;
    std::string russian;
    size_t counter = 0;
    
    size_t getCounter() const { return counter; }
    
    void setEnglish(std::string eng)
    {
        ++counter;
        english = eng;
    }
    
    void setRussian(std::string rus)
    {
        ++counter;
        russian = rus;
    }
    
    std::string translateRus()
    {
        ++counter;
        return russian;
    }
    std::string translateEng()
    {
        ++counter;
        return english;
    }
    
    friend std::ostream& operator<<(std::ostream& out, Dictionary& word)
    {
        word.counter++;
        out << std::left << std::setw(9) << word.counter << std::setw(15) << word.english << std::setw(15) << word.russian;
        return out;
    }
    
    friend std::ifstream& operator>>(std::ifstream& in, Dictionary& word)
    {
        in >> word.english >> word.russian >> word.counter;
        return in;
    }
    
    friend std::istream& operator>>(std::istream& in, Dictionary& word)
    {
        std::cout << "\nEnter a word in english: ";
        std::cin >> word.english;
        std::cout << "Enter a word in russian: ";
        std::cin >> word.russian;
        word.counter = 0;
        return in;
    }
};
