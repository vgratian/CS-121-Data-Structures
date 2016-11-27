#include <iostream>
#include "my_list.cpp"

int main() {

    my_list<int> data;

    std::cout << std::endl << "testing get_size" << std::endl;
    std::cout << "size: " << data.get_size() << std::endl;
    data.print();

    std::cout << std::endl << "testing is_empty" << std::endl;
    if(data.is_empty())
      std::cout << "yes: it's empty (size: " << data.get_size() << ")" << std::endl;
    else
      std::cout << "no: not empty (size: " << data.get_size() << ")" << std::endl;

    std::cout << std::endl << "testing pushfront" << std::endl;
    data.push_front(104);
    data.push_front(42);
    data.push_front(23);
    data.print();
    std::cout << "size: " << data.get_size() << std::endl;

    std::cout << std::endl << "testing insert" << std::endl;
    data.insert(5, 0);
    data.print();
    std::cout << "size: " << data.get_size() << std::endl;

    std::cout << std::endl << "testing remove" << std::endl;
    data.remove(0);
    data.print();
    std::cout << "size: " << data.get_size() << std::endl;

    std::cout << std::endl << "testing is_empty" << std::endl;
    if(data.is_empty())
      std::cout << "yes: it's empty (size: " << data.get_size() << ")" << std::endl;
    else
      std::cout << "no: not empty (size: " << data.get_size() << ")" << std::endl;

    return 0;
}
