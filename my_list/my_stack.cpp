#include "my_list.cpp"

template <class S>
class Stack {
protected:
  List<S> m_list;

public:
  Stack();
  bool is_empty();
  unsigned int get_size();
  void push(S value);
  void print();
  S pop();
  S get_top();
};

template <class S>
Stack<S>::Stack() { // default constructor
  List<S> m_list;
}

template <class S>
bool Stack<S>::is_empty() {
  return m_list.is_empty();
}

template <class S>
unsigned int Stack<S>::get_size() {
  return m_list.get_size();
}

template <class S>
void Stack<S>::push(S value) {    // adds element in front of the list
  m_list.push_front(value);
}

template <class S>
void Stack<S>::print() {
  m_list.print();
}

template <class S>
S Stack<S>::pop() {
  S value = m_list.get_data(0);
  m_list.remove(0);
  return value;
}

template <class S>
S Stack<S>::get_top() {
  return m_list.get_data(0);
}
