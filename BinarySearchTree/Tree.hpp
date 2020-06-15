#pragma once
#include<iostream>
#include<iomanip>
#include "Couple.hpp"
#include "Dictionary.hpp"

template<typename Type>
class Node
{
public:
    Type data;
    Node* left;
    Node* right;
    
    Node(const Type& temp_data, Node* temp_left = nullptr, Node* temp_right = nullptr) : data(temp_data), left(temp_left), right(temp_right) {};
    ~Node() = default;
};

template<typename Type>
class Tree
{
private:
    Node<Type>* root;
    
public:
    Tree() : root(nullptr) {}
    Tree(const Type& key) : root(new Node<Type>(key)) {}
    ~Tree() { deleteTree(root); }
    
    void add(const Type&);
    void erase(const Type&);
    void print();
    Type find(const Type&);
    Type findMin();
    Type findMax();
    void transfer(Tree<Couple<size_t, Dictionary>>&);
    
private:
    Node<Type>* add(Node<Type>*, const Type&);
    Node<Type>* erase(Node<Type>*, const Type&);
    void print(Node<Type>*);
    Type findElement(Node<Type>*,const Type&);
    void deleteTree(Node<Type>*);
    Node<Type>* findEdgeLeft(Node<Type>*);
    Node<Type>* findEdgeRight(Node<Type>*);
    void transfer(Node<Type>*, Tree<Couple<size_t, Dictionary>>&);
};

