#include "Tree.cpp"
#include "Couple.hpp"
#include "Dictionary.hpp"
#include <fstream>
#include <vector>


int main()
{
    Couple<std::string, Dictionary> couple_word, couple_word_find;
//    Couple<size_t, Dictionary> couple_rating;
    
    Tree<Couple<std::string, Dictionary>> tree_word; //дерево, отсортированное по ключу "English word"
//    Tree<Couple<size_t, Dictionary>> tree_rating; //дерево, отсортированное по ключу "Rating"
    
    std::string word;
    Dictionary node_dictionary;
    
    std::vector<Dictionary> vector_words;
    
    std::ifstream fin("Dictionary.txt");
    
    if (!fin) //создаем поток для чтения слов из файла
    {
        std::cout << "Error open file!\n";
        return 0;
    }
    
    while (!fin.eof()) //переносим все в вектор
    {
        fin >> node_dictionary;
        couple_word.makeCouple(node_dictionary.english, node_dictionary);
        tree_word.add(couple_word);
//        vector_words.push_back(node_dictionary);
    }
    
        for (std::vector<Dictionary>::iterator i = vector_words.begin(); i < vector_words.end(); i++)
        {
            std::cout << *i << "\n";
        }
    
    for (size_t i = 0; i < vector_words.size(); i++) //читаем все из вектора в дерево, отсортированное по ключу "English word"
    {
        couple_word.makeCouple(vector_words[i].english, vector_words[i]);
        tree_word.add(couple_word);
    }
    
    //    int choiceTree;
    //    std::cout << "How do you want to build a tree?\n 1. std::string and Dictionary\n 2. size_t and Dictionary\n";
    //    std::cin >> choiceTree;
    //    switch (choiceTree)
    //    {
    //        case 1:
    //            for (size_t i = 0; i < vector_words.size(); i++)
    //            {
    //                couple_word.makeCouple(vector_words[i].english, vector_words[i]);
    //                tree_word.add(couple_word);
    //            }
    //            break;
    //        case 2:
    //
    //            for (size_t i = 0; i < vector_words.size(); i++)
    //            {
    //                couple_rating.makeCouple(vector_words[i].counter, vector_words[i]);
    //                tree_rating.add(couple_rating);
    //            }
    //            break;
    //        default: break;
    //    }
    
    bool flag = true;
    
    while (flag)
    {
        std::cout << "\nCommand:\n"
        << "1. Add word\n"
        << "2. Replace\n"
        << "3. Erase\n"
        << "4. Find word\n"
        << "5. Print tree\n"
        << "6. Find less popular words\n"
        << "7. Find most popular words\n"
        << "0. Exit\n"
        << "\nEnter command: ";
        
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 0: //exit
            {
                for (std::vector<Dictionary>::iterator i = vector_words.begin(); i < vector_words.end(); i++)
                {
                    std::cout << *i << "\n";
                }
                
                flag = false;
                break;
            }
            case 1: //find word
            {
                std::cin >> node_dictionary;
                couple_word.makeCouple(node_dictionary.english, node_dictionary);
                tree_word.add(couple_word);
                break;
            }
            case 2: //replace
            {
                std::string word_rus;
                std::cout << "Enter a word to replace: ";
                std::cin >> word;
                std::cout << "Enter new russian word: ";
                std::cin >> word_rus;
                Couple<std::string, Dictionary> couple_replace, couple_word;
                couple_replace.makeCouple(word, node_dictionary);
                couple_word = tree_word.find(couple_replace);
                couple_word.second.setRussian(word_rus);
                tree_word.erase(couple_replace);
                tree_word.add(couple_word);
                break;
            }
                
            case 3: //erase
            {
                std::cout << "Enter a word to erase: ";
                std::cin >> word;
                Couple<std::string, Dictionary> couple_erase;
                couple_erase.makeCouple(word, node_dictionary);
                tree_word.erase(couple_erase);
                break;
            }
            case 4: //find word
            {
                std::cout << "Enter a word in english: ";
                std::cin >> word;
                couple_word_find.makeCouple(word, node_dictionary);
                std::cout << "Translation: ";
                couple_word = tree_word.find(couple_word_find);
                std::cout << couple_word.second.translateRus() << std::endl;
                break;
            }
            case 5: //print
            {
                tree_word.print();
                break;
            }
            case 6: //find less popular words
            {
//                Couple<size_t, Dictionary> temp;
//                Tree<Couple<size_t, Dictionary>> tree_rating; //дерево, отсортированное по ключу "Rating"
//                
//                temp = tree_rating.findMin();
//                tree_rating.erase(temp);
//                temp = tree_rating.findMin();
//                tree_rating.erase(temp);
//                temp = tree_rating.findMin();
//                tree_rating.erase(temp);
//                std::cout << temp << std::endl;
//                break;
            }
            case 7: //find most popular words
            {
//                Couple<size_t, Dictionary> temp;
//                temp = tree_rating.findMax();
//                tree_rating.erase(temp);
//                std::cout << temp << std::endl;
//                break;
            }
            default:
            {
                std::cout << "Not command!\n";
                break;
            }
        }
    }
    
    return 0;
}
