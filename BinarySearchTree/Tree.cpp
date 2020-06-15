#include "Tree.hpp"

template<typename Type>
void Tree<Type>::add(const Type& key)
{
    root = add(root, key);
}

template<typename Type>
Node<Type>* Tree<Type>::add(Node<Type>* root, const Type& key)
{
    if (root == nullptr)
    {
        Node<Type>* newRoot = new Node<Type>(key);
        root = newRoot;
        return root;
    }
    else
    {
        if (key < root->data)
        {
            root->left = add(root->left, key);
        }
        else
        {
            root->right = add(root->right, key);
        }
    }
    
    return root;
}

template<typename Type>
void Tree<Type>::erase(const Type& key)
{
    root = erase(root, key);
}

template<typename Type>
Node<Type>* Tree<Type>::erase(Node<Type>* root, const Type& key)
{
    Node<Type>* temp = nullptr;
    
    if (root == nullptr)
    {
        std::cout << "Error! Not found!\n";
        return nullptr;
    }
    else if (key < root->data)
    {
        root->left = erase(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = erase(root->right, key);
    }
    else
    {
        bool flag = true;
        temp = root;
        
        if (root->right != nullptr)
        {
            if (root->right->data == key)
            {
                flag = false;
                root->right = erase(root->right, key);
            }
        }
        
        if (flag)
        {
            if (root->left == nullptr)
            {
                temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                temp = root->left;
                delete root;
                return temp;
            }
            
            temp = findEdgeLeft(root->right);
            root->data = temp->data;
            root->right = erase(root->right, temp->data);
        }
    }
    
    return root;
}

template<typename Type>
void Tree<Type>::print()
{
    std::cout << std::left << std::setw(10) << "\nRating" << std::setw(15) << "English word" << std::setw(15) << "Русское слово" << "\n";
    print(root);
}

template<typename Type>
void Tree<Type>::print(Node<Type>* root)
{
    if (root != nullptr)
    {
        print(root->left);
        std::cout << root->data;
        print(root->right);
    }
    else
    {
        return;
    }
}

template<typename Type>
Type Tree<Type>::find(const Type& key)
{
    return findElement(root, key);
}

template<typename Type>
Type Tree<Type>::findElement(Node<Type>* root, const Type& key)
{
    if (root == nullptr)
    {
        std::cout << "Not found!\n";
        return Type();
    }
    else if (root->data == key)
    {
        return root->data;
    }
    else
    {
        if (key < root->data)
        {
            return findElement(root->left, key);
        }
        else
        {
            return findElement(root->right, key);
        }
    }
}

template<typename Type>
void Tree<Type>::deleteTree(Node<Type>* root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    else
    {
        return;
    }
}

template<typename Type>
Node<Type>* Tree<Type>::findEdgeLeft(Node<Type>* root)
{
    Node<Type>* temp = root;
    
    while (temp != nullptr && temp->left != nullptr)
    {
        temp = temp->left;
    }
    
    return temp;
}

template<typename Type>
Node<Type>* Tree<Type>::findEdgeRight(Node<Type>* root)
{
    Node<Type>* temp = root;
    
    while (temp != nullptr && temp->right != nullptr)
    {
        temp = temp->right;
    }
    
    return temp;
}

template<typename Type>
Type Tree<Type>::findMin()
{
    Node<Type>* temp = findEdgeLeft(root);
    return temp->data;
}

template<typename Type>
Type Tree<Type>::findMax()
{
    Node<Type>* temp = findEdgeRight(root);
    return temp->data;
}

template<typename Type>
void Tree<Type>::transfer(Tree<Couple<size_t, Dictionary>>& tree)
{
    transfer(root, tree);
}

template<typename Type>
void Tree<Type>::transfer(Node<Type>* root, Tree<Couple<size_t, Dictionary>>& tree)
{
    Couple<size_t, Dictionary> couple_word;
        
    if (root != nullptr)
    {
        transfer(root->left, tree);
        couple_word.makeCouple(root->data.second.counter, root->data.second);
        tree.add(couple_word);
        transfer(root->right, tree);
    }
    else
    {
        return;
    }
}
