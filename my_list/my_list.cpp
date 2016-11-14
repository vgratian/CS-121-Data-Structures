#include <iostream>
using namespace std;

template <class N>
class node {
public:
  N data;
  node* next;
};

template <class L>
class my_list {
private:
  node<L>* m_head;
  node<L>* m_end;
  unsigned int m_size;

public:
  my_list() { // default constructor
    m_head = NULL;
    m_size = 0;
  }

  unsigned int get_size() {
    return m_size;
  }

  void push_front(L value) {
    node<L>* el = new node<L>; // el is the new element
    el->data = value;
    el->next = m_head;
    m_head = el;
    m_size++;
  }

  void insert(L value, unsigned int position) {
    if(position == 0) {
      push_front(value);
    }

    else {
      node<L>* el = new node<L>;
      el->data = value;

      node<L>* prev = m_head; // prev is the previous node
      while(position > 1) {
        prev = prev->next;
        position--;
      }

      el->next = prev->next;
      prev->next = el;
      m_size++;
    }
  }

  void remove(unsigned int position) {
    node<L>* el = m_head;

    if(position == 0) {
      m_head = el->next;
    }

    else {
      node<L>* prev = m_head;   // to identify the previous element
      for(int i=position; i > 1; i--) {
        prev = prev->next;
      }

      el = prev->next;
      prev->next = el->next;
    }
      delete el;
      m_size--;
    }

  void print() {
    node<L>* element = m_head; // element == each element in the list
    while(element != NULL) {
      cout << element->data << endl;
      element = element->next;
    }
  }

  void destructor() {
    ;
  }

};

int main() {

    my_list<int> velocities;
    cout << "size: " << velocities.get_size() << endl;
    velocities.print();

    cout << endl << "testing pushfront" << endl;
    velocities.push_front(42);
    velocities.push_front(1984);
    velocities.push_front(23);
    cout << "size: " << velocities.get_size() << endl;
    velocities.print();

    cout << endl << "testing insert" << endl;
    velocities.insert(1985, 1);
    cout << "size: " << velocities.get_size() << endl;
    velocities.print();

    cout << endl << "testing remove" << endl;
    velocities.remove(3);
    //velocities.remove(0);
    cout << "size: " << velocities.get_size() << endl;
    velocities.print();

    return 0;
}
