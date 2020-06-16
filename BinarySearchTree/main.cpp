#include "Tree.cpp"
#include "Couple.hpp"
#include "Dictionary.hpp"
#include <fstream>

int main()
{
    std::cout << "Task 1. Dictionary\n";
    Couple<std::string, Dictionary> couple_word, couple_word_find;
    Tree<Couple<std::string, Dictionary>> tree_word; //дерево по ключу "English word"
    Dictionary node_dictionary;
    std::ifstream fin("Dictionary.txt");
    
    if (!fin) //создаем поток для чтения слов из файла
    {
        std::cout << "Error open file!\n";
        return 0;
    }
    
    while (!fin.eof()) //переносим все в бинаверное дерево
    {
        fin >> node_dictionary;
        couple_word.makeCouple(node_dictionary.english, node_dictionary);
        tree_word.add(couple_word);
    }
    
    bool flag = true;
    
    while (flag) //меню команд
    {
        std::cout << "\nCommand:\n"
        << "1. Add word\n"
        << "2. Replace\n"
        << "3. Erase\n"
        << "4. Find word\n"
        << "5. Print dictionary\n"
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
                flag = false;
                break;
            }
            case 1: //add word
            {
                std::cin >> node_dictionary;
                couple_word.makeCouple(node_dictionary.english, node_dictionary);
                tree_word.add(couple_word);
                break;
            }
            case 2: //replace
            {
                std::string word, word_rus;
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
                std::string word;
                std::cout << "Enter a word to erase: ";
                std::cin >> word;
                Couple<std::string, Dictionary> couple_erase;
                couple_erase.makeCouple(word, node_dictionary);
                tree_word.erase(couple_erase);
                break;
            }
            case 4: //find word
            {
                Node<Couple<std::string, Dictionary>>* root = nullptr;
                std::string word;
                std::cout << "Enter a word in english: ";
                std::cin >> word;
                couple_word_find.makeCouple(word, node_dictionary);
                std::cout << "Translation: ";
                root = tree_word.findNode(couple_word_find);
                
                if (root)
                {
                    std::cout << root->data.second.translateRus() << "\n";
                }
                
                break;
            }
            case 5: //print
            {
                tree_word.print();
                break;
            }
            case 6: //find less popular words
            {
                Tree<Couple<size_t, Dictionary>> tree_rating;
                Couple<size_t, Dictionary> temp;
                tree_word.transfer(tree_rating);
                size_t count = 3;
                std::cout << "\nLess popular words:\n";
                
                while (count)
                {
                    temp = tree_rating.findMin();
                    std::cout << temp.second.translateEng() << "\n";
                    tree_rating.erase(temp);
                    count--;
                }
                
                break;
            }
            case 7: //find most popular words
            {
                Tree<Couple<size_t, Dictionary>> tree_rating;
                Couple<size_t, Dictionary> temp;
                tree_word.transfer(tree_rating);
                size_t count = 3;
                std::cout << "\nMost popular words:\n";
                
                while (count)
                {
                    temp = tree_rating.findMax();
                    std::cout << temp.second.translateEng() << "\n";
                    tree_rating.erase(temp);
                    count--;
                }
                
                break;
            }
            default:
            {
                std::cout << "Not command!\n";
                break;
            }
        }
    }
    
    fin.close();
    system("pause");
    return 0;
}
