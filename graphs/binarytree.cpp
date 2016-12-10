#include <iostream>

template <class N>
class Node {
public:
  N data;
  Node* left;
  Node* right;
};

template <class B>
class BinaryTree {
protected:
  Node<B>* m_root;
  unsigned int m_height;
  unsigned int m_size;    // contains the total number of nodes

public:

BinaryTree() {          // defailt constructor
  m_root = NULL;
  m_height = 0;
  m_size = 0;
}

bool is_empty() {
  if(m_size==0)
    return true;
  return false;
}

bool find(B value) {
  Node<B>* parent = m_root;
  return __find(parent, value);
}

bool __find(Node<B>* parent, B value) {
  if(parent != NULL) {
    if(value == parent->data)
      return true;
    else if(value < parent->data)
      __find(parent->left, value);
    else if(value > parent->data)
      __find(parent->right, value);
  }
  else
    return false;
}

int get_size() {
  return m_size;
}

int get_height() {
  ;
}

void insert(B value) {
  if(m_root == NULL) {
    m_root = new Node<B>;
    m_root->data = value;
    m_root->left = NULL;
    m_root->right = NULL;
  }
  else {
    Node<B>* parent = m_root;
    __insert(parent, value);
  }
}

void __insert(Node<B>* parent, B value) {
  if(value < parent->data) {
    if(parent->left != NULL)
      __insert(parent->left, value);
    else {
      parent->left = new Node<B>;
      parent->left->data = value;
      parent->left->left = NULL;
      parent->left->right = NULL;
      m_size++;
    }
  }
  else if(value >= parent->data) {
    if(parent->right != NULL)
      __insert(parent->right, value);
    else {
        parent->right = new Node<B>;
        parent->right->data = value;
        parent->right->left = NULL;
        parent->right->right = NULL;
        m_size++;
    }
  }
}

void remove() {
  ;
}

void traverse() {
  ;
}

void print() {
  Node<B>* element = m_root; // element == each element in the list
  __print(element);
  std::cout << std::endl;
}

void __print(Node<B>* element) {
  if(element != NULL) {
    __print(element->left);
    __print(element->right);
    std::cout << element->data << " ";
  }
}

};

int main() {

  BinaryTree<int> tree;
  std::cout << "size: " << tree.get_size() << std::endl;
  tree.insert(5);
  tree.insert(6);
  tree.insert(12);
  tree.insert(1);
  tree.insert(7);
  std::cout << "size: " << tree.get_size() << std::endl;
  std::cout << "testing print" << std::endl;
  tree.print();

  std::cout << "testing find(7): " << tree.find(7) << std::endl;
  std::cout << "testing find(7): " << tree.find(50) << std::endl;

  std::cout << "testing get_height : " << tree.get_height() << std::endl;

  return 0;
}
