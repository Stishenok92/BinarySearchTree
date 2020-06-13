#include "Tree.cpp"
#include "Couple.hpp"
#include "Dictionary.hpp"
#include <fstream>
#include <vector>


int main()
{
    
    Couple<std::string, Dictionary> couple_word, couple_word_find;
    Couple<size_t, Dictionary> couple_rating, couple_rating_find;
    std::string word = "penguin";
    std::string word1 = "mango";
    Dictionary d, d1;
    
    //std::cin >> d >> d1;
    
    /*cpl.makeCouple(word, d);
     cpl1.makeCouple(word1, d1);*/
    
    Tree<Couple<std::string, Dictionary>> tree_word;
    Tree<Couple<size_t, Dictionary>> tree_rating;
    
    std::vector<Dictionary> words;
    std::ifstream in("Text.txt");
    
    while (!in.eof())
    {
        in >> d;
        words.push_back(d);
    }
    
    for (std::vector<Dictionary>::iterator i = words.begin(); i < words.end(); i++)
    {
        std::cout << *i << " ";
        std::cout << std::endl;
    }
    
    int choiceTree;
    std::cout << "How do you want to build a tree?\n 1. std::string and Dictionary\n 2. size_t and Dictionary\n";
    std::cin >> choiceTree;
    switch (choiceTree)
    {
        case 1:
            for (size_t i = 0; i < words.size(); i++)
            {
                couple_word.makeCouple(words[i].english, words[i]);
                tree_word.add(couple_word);
            }
            break;
        case 2:

            for (size_t i = 0; i < words.size(); i++)
            {
                couple_rating.makeCouple(words[i].counter, words[i]);
                tree_rating.add(couple_rating);
            }
            break;
        default: break;
    }
    
    bool flag = true;
    while (flag)
    {
        std::cout << "Enter command.\n"
        << "1. find word\n2. replace\n3. erase\n4. print tree\n"
        "5. find less popular words\n 6. find most popular words\n7. exit";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                std::cout << "Enter a word in english: ";
                std::cin >> word;
                
                couple_word_find.makeCouple(word, d);
                couple_word = tree_word.find(couple_word_find);
                std::cout << couple_word.second.translateRus() << std::endl;
                break;
            }
            case 2:
            {
                std::string rusWord;
                std::cout << "Enter a word to replace: ";
                std::cin >> word >> rusWord;
                Couple<std::string, Dictionary> coupleToReplace, couple_word;
                
                coupleToReplace.makeCouple(word, d);
                couple_word = tree_word.find(coupleToReplace);
                
                couple_word.second.setRussian(rusWord);
                
                tree_word.erase(coupleToReplace);
                tree_word.add(couple_word);
                
                break;
            }
            case 3:
            {
                std::cout << "Enter a word to erase: ";
                std::cin >> word;
                Couple<std::string, Dictionary> coupleToErase;
                coupleToErase.makeCouple(word, d);
                tree_word.erase(coupleToErase);
                break;
            }
            case 4:
            {
                tree_word.print();
                break;
            }
            case 5:
            {
                Couple<size_t, Dictionary> temp;
                temp = tree_rating.findMin();
                tree_rating.erase(temp);
                temp = tree_rating.findMin();
                tree_rating.erase(temp);
                temp = tree_rating.findMin();
                tree_rating.erase(temp);
                std::cout << temp << std::endl;
                break;
            }
            case 6:
            {
                Couple<size_t, Dictionary> temp;
                temp = tree_rating.findMax();
                tree_rating.erase(temp);
                std::cout << temp << std::endl;
                
                break;
            }
            case 7:
            {
                flag = false;
                break;
            }
            default:
                break;
        }
    }
    
    return 0;
}
