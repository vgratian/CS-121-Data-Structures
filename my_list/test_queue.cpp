#include <iostream>
#include "my_queue.cpp"

main() {
  Queue<int> q;

  std::cout << std::endl << "testing 'is empty'" << std::endl;
  if(q.is_empty())
    std::cout << "yes: it's empty (size: " << q.get_size() << ")" << std::endl;
  else
    std::cout << "no: not empty (size: " << q.get_size() << ")" << std::endl;

  std::cout << std::endl << "testing 'enqueue'" << std::endl;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.print();

  std::cout << std::endl << "testing 'dequeue'" << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << "size: " << q.get_size() << std::endl;

  std::cout << std::endl << "testing 'get front'" << std::endl;
  std::cout << q.get_front() << std::endl;
  std::cout << "size: " << q.get_size() << std::endl;


  std::cout << std::endl << "testing 'is empty'" << std::endl;
  if(q.is_empty())
    std::cout << "yes: it's empty (size: " << q.get_size() << ")" << std::endl;
  else
    std::cout << "no: not empty (size: " << q.get_size() << ")" << std::endl;

return 0;
}
