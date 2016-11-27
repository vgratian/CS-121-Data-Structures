#include <iostream>
#include "my_list.cpp"

int main() {

    my_list<int> l;

    std::cout << std::endl << "testing get_size" << std::endl;
    std::cout << "size: " << l.get_size() << std::endl;
    l.print();

    std::cout << std::endl << "testing is_empty" << std::endl;
    if(l.is_empty())
      std::cout << "yes: it's empty (size: " << l.get_size() << ")" << std::endl;
    else
      std::cout << "no: not empty (size: " << l.get_size() << ")" << std::endl;

    std::cout << std::endl << "testing pushfront" << std::endl;
    l.push_front(104);
    l.push_front(42);
    l.push_front(23);
    l.print();
    std::cout << "size: " << l.get_size() << std::endl;

    std::cout << std::endl << "testing insert" << std::endl;
    l.insert(5, 0);
    l.print();
    std::cout << "size: " << l.get_size() << std::endl;

    std::cout << std::endl << "testing remove" << std::endl;
    l.remove(0);
    l.print();
    std::cout << "size: " << l.get_size() << std::endl;

    std::cout << std::endl << "testing is_empty" << std::endl;
    if(l.is_empty())
      std::cout << "yes: it's empty (size: " << l.get_size() << ")" << std::endl;
    else
      std::cout << "no: not empty (size: " << l.get_size() << ")" << std::endl;

    return 0;
}
