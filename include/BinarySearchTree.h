//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
#include <utility>
#include <algorithm>

template <typename K, typename V>
class BinarySearchTree {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(const K& key, const V& value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, const K& key, const V& value);
    void inOrderTraversal(Node* node, std::vector<std::pair<K, V>>& result) const;
    void clear(Node* node);

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(root); }

    void insert(const K& key, const V& value);
    std::vector<std::pair<K, V>> getSortedElements() const;
};

// Include the implementation file
//#include "BinarySearchTree.tpp"

#endif // BINARYSEARCHTREE_H


