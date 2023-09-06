#include <iostream>

#ifndef BINARY_SEARCH_TREE

#define BINARY_SEARCH_TREE

// clase nodo estandar
template <typename T> class BSTNode {
public:
  BSTNode(const T &value, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr)
      : data{value}, left{l}, right{r} {}
  ~BSTNode() {}

  T data{};
  BSTNode<T> *left{}, *right{};
};

// Arbol binario de busqueda sin balancear
template <typename T> class BST {
protected:
  BSTNode<T> *root{};

private:
  /** cuenta el numero de comparaciones entre valores de nodos*/
  size_t comparasions{};
  /** Devuelve el nodo padre del valor y null si el valor ya esta insertado
   */
  BSTNode<T> *findParent(const T &value) {
    BSTNode<T> *current = root;
    BSTNode<T> *previus = nullptr;
    while (current != nullptr) {
      previus = current;
      if (value < current->data) {
        current = current->left;
        comparasions++;
      } else if (value > current->data) {
        current = current->right;
        comparasions += 2;
      } else {
        comparasions += 2; // No olvidar los if's anteriores
        return nullptr;    // Esto implica que el valor ya esta insertado
      }
    }
    return previus;
  }

public:
  BST() {}
  ~BST() {}
  /** Inserta el valor sin duplicarlo
   */
  void insert(const T &value) {
    BSTNode<T> *previus = findParent(value);

    if (root == nullptr) {
      root = new BSTNode<T>{value};
    } else if (previus == nullptr) { // El valor esta insertado
      return;
    } else if (value < previus->data) {
      previus->left = new BSTNode<T>{value};
      comparasions++;
    } else if (value > previus->data) {
      previus->right = new BSTNode<T>{value};
      comparasions += 2;
    } else {
      comparasions += 2; // No olvidar los if's anteriores
    }
  }
  void inorder(BSTNode<T> *tree) {
    if (tree != nullptr) {
      inorder(tree->left);
      std::cout << tree->data << ' ';
      inorder(tree->right);
    }
  }
  void inorder() { inorder(root); }
  size_t getNumberOfComparasions() { return comparasions; }
};

#endif
