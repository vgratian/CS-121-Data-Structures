#include <iostream>
#include "binarytree.cpp"

int main() {

  BinaryTree<int> tree;
  std::cout << "size: " << tree.get_size() << std::endl;
  tree.insert(5);
  tree.insert(7);
  tree.insert(12);
  tree.insert(1);
  tree.insert(8);
  tree.insert(6);
  std::cout << "size: " << tree.get_size() << std::endl;

  std::cout << "testing find(7): " << tree.find(7) << std::endl;
  std::cout << "testing find(7): " << tree.find(50) << std::endl;

  std::cout << "testing get_height: " << tree.get_height() << std::endl;

  std::cout << "testing preorder" << std::endl;
  tree.preorder();
  std::cout << "testing inorder" << std::endl;
  tree.inorder();
  std::cout << "testing postorder" << std::endl;
  tree.postorder();

  std::cout << "testing remove(7)" << std::endl;
  //tree.remove(1);
  tree.remove(7);
  tree.postorder();

  return 0;
}
