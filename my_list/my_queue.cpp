#include "my_list.cpp"

template <class Q>
class Queue {
protected:
  List<Q> m_list;

public:
  Queue();
  bool is_empty();
  unsigned int get_size();
  void enqueue(Q value);
  void print();
  Q dequeue();
  Q get_front();
};

template <class Q>
Queue<Q>::Queue() {
  List<Q> m_list;
}

template <class Q>
bool Queue<Q>::is_empty() {
  return m_list.is_empty();
}

template <class Q>
unsigned int Queue<Q>::get_size() {
  return m_list.get_size();
}

template <class Q>
void Queue<Q>::enqueue(Q value) { // adds new element at the end of the list
  m_list.push_back(value);
}

template <class Q>
void Queue<Q>::print() {
  m_list.print();
}

template <class Q>
Q Queue<Q>::dequeue() {  // returns and deletes first element of the list
  Q data = m_list.get_data(0);
  m_list.remove(0);
  return data;
}

template <class Q>
Q Queue<Q>::get_front() { // returns first element of the list
  return m_list.get_data(0);
}
