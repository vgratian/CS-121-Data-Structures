template <class N>
class Node {
public:
  N data;
  Node* left;
  Node* right;
  Node* parent;
};

template <class B>
class BinaryTree {
protected:
  Node<B>* m_root;
  unsigned int m_height;  // longest path in tree
  unsigned int m_size;    // total number of nodes

  // methods that support public methods of below
  void __insert(Node<B>* element, B value);
  void __inorder(Node<B>* element);
  void __preorder(Node<B>* element);
  void __postorder(Node<B>* element);
  void __remove(Node<B>* element, B value);
  void __update_parent(Node<B> *element);
  void __destroy_tree(Node<B>* element);
  int __get_height(Node<B>* element);
  Node<B>* __find(Node<B>* element, B value);
  Node<B>* __find_minimal(Node<B> *element);

public:
  BinaryTree(); // Default constructor
  ~BinaryTree(); // Default deconstructor
  void insert(B value);
  void inorder();
  void preorder();
  void postorder();
  void remove(B value);
  int get_size();
  int get_height();
  bool is_empty();
  bool find(B value);
};

template <class B>
BinaryTree<B>::BinaryTree() {
  m_root = NULL;
  m_height = 0;
  m_size = 0;
}

template <class B>
BinaryTree<B>::~BinaryTree() {
  __destroy_tree(m_root);
}

template <class B>
void BinaryTree<B>::insert(B value) {      // Creates a new node in the tree with value
  if(m_root == NULL) {
    m_root = new Node<B>;   // creating the root if it's empty
    m_root->data = value;
    m_root->left = NULL;
    m_root->right = NULL;
    m_root->parent = NULL;
  }
  else {
    Node<B>* element = m_root;
    __insert(element, value);
  }
}

template <class B>
void BinaryTree<B>::__insert(Node<B>* element, B value) {
  if(value < element->data) {
    if(element->left != NULL)
      __insert(element->left, value);
    else {
      element->left = new Node<B>;
      element->left->data = value;
      element->left->left = NULL;
      element->left->right = NULL;
      element->left->parent = element;
      m_size++;
    }
  }
  else if(value >= element->data) {
    if(element->right != NULL)
      __insert(element->right, value);
    else {
        element->right = new Node<B>;
        element->right->data = value;
        element->right->left = NULL;
        element->right->right = NULL;
        element->right->parent = element;
        m_size++;
    }
  }
}

// Traversals: Inorder, Preorder and Postorder
template <class B>
void BinaryTree<B>::inorder() {
  __inorder(m_root);
  std::cout << std::endl;
}

template <class B>
void BinaryTree<B>::__inorder(Node<B>* element) {
  if(element != NULL) {
    __inorder(element->left);
    std::cout << element->data << " ";
    __inorder(element->right);
  }
}

template <class B>
void BinaryTree<B>::preorder() {
  __preorder(m_root);
  std::cout << std::endl;
}

template <class B>
void BinaryTree<B>::__preorder(Node<B>* element) {
  if(element != NULL) {
    std::cout << element->data << " ";
    __preorder(element->left);
    __preorder(element->right);
  }
}

template <class B>
void BinaryTree<B>::postorder() {
  __postorder(m_root);
  std::cout << std::endl;
}

template <class B>
void BinaryTree<B>::__postorder(Node<B>* element) {
  if(element != NULL) {
    __postorder(element->left);
    __postorder(element->right);
    std::cout << element->data << " ";
  }
}


template <class B>
void BinaryTree<B>::remove(B value) {   // Removes node from tree
  __remove(m_root, value);
}

template <class B>
void BinaryTree<B>::__remove(Node<B>* element, B value) {
  if(value < element->data)
    __remove(element->left, value);
  else if(value > element->data)
    __remove(element->right, value);

  else {  // when we have the element that needs to be deleted
    // Case 1: element has no children
    if(element->left == NULL && element->right == NULL) {
      __update_parent(element);
      delete element;
      //std::cout << "Case 1 : deleted!" << std::endl;
    }
    // Case 2: element has 1 child
    else if((element->left == NULL) != (element->right == NULL)) {
      if(element->left != NULL) {
        element = element->left;
        element->left = NULL;
        delete element->left;
        //std::cout << "Case 2 : deleted!" << std::endl;
      }
      else if(element->right != NULL) {
        element = element->right;
        element->right = NULL;
        delete element->right;
        //std::cout << "Case 2 : deleted!" << std::endl;
      }
    }
    // Case 3: element has 2 children
    else if(element->left != NULL && element->right != NULL) {
      Node<B> *temp = __find_minimal(element->right);
      element = temp;
      __update_parent(temp);
      delete temp;
      //std::cout << "Case 3 : deleted!" << std::endl;
    }
    m_size--;
  }
}

template <class B>
void BinaryTree<B>::__update_parent(Node<B> *element) {  // If element has parent, removes
                                          // the link from parent to elmement
  if(element->parent != NULL) {
    if(element->parent->left == element)  element->parent->left = NULL;
    else if(element->parent->right == element)  element->parent->right = NULL;
  }
}

template <class B>
void BinaryTree<B>::__destroy_tree(Node<B>* element) {   // Deletes all elements in the tree
  if(element != NULL){
    __destroy_tree(element->left);
    __destroy_tree(element->right);
    delete element;
  }
}

template <class B>
int BinaryTree<B>::get_size() {    // Returns number of nodes in the tree
  return m_size;
}

template <class B>
int BinaryTree<B>::get_height() {    // Returns the longest path in the tree
  return __get_height(m_root);
}

template <class B>
int BinaryTree<B>::__get_height(Node<B>* element) {
  if(element == NULL)
    return 0;
  else
    return 1 + std::max(__get_height(element->left),__get_height(element->right));
}

template <class B>
bool BinaryTree<B>::is_empty() {   // Checks if tree is empty
  if(m_size==0)
    return true;
  return false;
}

template <class B>
bool BinaryTree<B>::find(B value) {    // Checks if tree has any node with value
  Node<B>* element = __find(m_root, value);
  if(element != NULL)
    return true;
  return false;
}

template <class B>
Node<B>* BinaryTree<B>::__find(Node<B>* element, B value) {
  if(element != NULL) {
    if(value == element->data)
      return element;
    else if(value < element->data)
      __find(element->left, value);
    else if(value > element->data)
      __find(element->right, value);
  }
  else
    return NULL;
}

template <class B>
Node<B>* BinaryTree<B>::__find_minimal(Node<B> *element) {
  Node<B> *temp = element;
  while(temp->left != NULL)
    temp = temp->left;
  std::cout << "find minimal: " << temp->data << std::endl;
  return temp;
}
