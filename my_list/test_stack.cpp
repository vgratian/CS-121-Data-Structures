#include <iostream>
#include "my_stack.cpp"

int main(){

  my_stack<int> stack;

  std::cout << std::endl << "testing 'is_empty'" << std::endl;
  if(stack.is_empty())
    std::cout << "yes: it's empty (size: " << stack.get_size() << ")" << std::endl;
  else
    std::cout << "no: not empty (size: " << stack.get_size() << ")" << std::endl;

  std::cout << std::endl << "testing 'push'" << std::endl;
  stack.push(10);
  stack.push(9);
  stack.push(8);
  stack.push(7);
  stack.print();
  std::cout << "size: " << stack.get_size() << std::endl;

  std::cout << std::endl << "testing 'pop'" << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << "size: " << stack.get_size() << std::endl;

  std::cout << std::endl << "testing 'get top'" << std::endl;
  std::cout << stack.get_top() << std::endl;
  std::cout << "size: " << stack.get_size() << std::endl;

  std::cout << std::endl << "testing 'is_empty'" << std::endl;
  if(stack.is_empty())
    std::cout << "yes: it's empty (size: " << stack.get_size() << ")" << std::endl;
  else
    std::cout << "no: not empty (size: " << stack.get_size() << ")" << std::endl;

  return 0;
}
