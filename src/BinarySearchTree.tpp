//
//
// Santiago Quintana Moreno A01571222
// Created on: 16/11/2024.
#include "BinarySearchTree.h"

template<typename K, typename V>
void BinarySearchTree<K, V>::insert(Node *&node, const K &key, const V &value) {
    if (!node) {
        node = new Node(key, value);
    } else if (key < node->key) {
        insert(node->left, key, value);
    } else if (key > node->key) {
        insert(node->right, key, value);
    }
}

template<typename K, typename V>
void BinarySearchTree<K, V>::insert(const K &key, const V &value) {
    insert(root, key, value);
}

template<typename K, typename V>
void BinarySearchTree<K, V>::inOrderTraversal(Node *node, std::vector<std::pair<K, V>> &result) const {
    if (node) {
        inOrderTraversal(node->left, result);
        result.emplace_back(node->key, node->value);
        inOrderTraversal(node->right, result);
    }
}

template<typename K, typename V>
std::vector<std::pair<K, V>> BinarySearchTree<K, V>::getSortedElements() const {
    std::vector<std::pair<K, V>> result;
    inOrderTraversal(root, result);
    std::sort(result.rbegin(), result.rend()); // Sort in descending order
    return result;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::clear(Node *node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
