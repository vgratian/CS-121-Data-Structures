#include <iostream>
#include "my_stack.cpp"

int main(){

  my_stack<int> s;

  std::cout << std::endl << "testing 'is empty'" << std::endl;
  if(s.is_empty())
    std::cout << "yes: it's empty (size: " << s.get_size() << ")" << std::endl;
  else
    std::cout << "no: not empty (size: " << s.get_size() << ")" << std::endl;

  std::cout << std::endl << "testing 'push'" << std::endl;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.print();
  std::cout << "size: " << s.get_size() << std::endl;

  std::cout << std::endl << "testing 'pop'" << std::endl;
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
  std::cout << "size: " << s.get_size() << std::endl;

  std::cout << std::endl << "testing 'get top'" << std::endl;
  std::cout << s.get_top() << std::endl;
  std::cout << "size: " << s.get_size() << std::endl;

  std::cout << std::endl << "testing 'is empty'" << std::endl;
  if(s.is_empty())
    std::cout << "yes: it's empty (size: " << s.get_size() << ")" << std::endl;
  else
    std::cout << "no: not empty (size: " << s.get_size() << ")" << std::endl;

  return 0;
}
