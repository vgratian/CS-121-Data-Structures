#include <iostream>
#include "my_list.cpp"

int main() {

    my_list<int> velocities;
    std::cout << "size: " << velocities.get_size() << std::endl;
    velocities.print();

    std::cout << std::endl << "testing is_empty" << std::endl;
    if(velocities.is_empty())
      std::cout << std::endl << "yes: it's empty" << std::endl;
    std::cout << std::endl << "not: not empty" << std::endl;

    std::cout << std::endl << "testing pushfront" << std::endl;
    velocities.push_front(104);
    velocities.push_front(42);
    velocities.push_front(23);
    std::cout << "size: " << velocities.get_size() << std::endl;
    velocities.print();

    std::cout << std::endl << "testing insert" << std::endl;
    velocities.insert(5, 0);
    std::cout << "size: " << velocities.get_size() << std::endl;
    velocities.print();

    std::cout << std::endl << "testing remove" << std::endl;
    velocities.remove(3);
    //velocities.remove(0);
    std::cout << "size: " << velocities.get_size() << std::endl;
    velocities.print();

    std::cout << std::endl << "testing is_empty" << std::endl;
    if(velocities.is_empty())
      std::cout << std::endl << "yes: it's empty" << std::endl;
    std::cout << std::endl << "no: not empty" << std::endl;

    return 0;
}
