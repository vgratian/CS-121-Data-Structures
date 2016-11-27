template <class N>
class node {
public:
  N data;
  node* next;
};

template <class L>
class my_list {
protected:
  node<L>* m_head;
  unsigned int m_size;

public:
  my_list() { // default constructor
    m_head = NULL;
    m_size = 0;
  }

  bool is_empty() {
    if(m_size == 0)
      return true;
    return false;
  }

  unsigned int get_size() {
    return m_size;
  }

  void push_front(L value) {
    node<L>* newel = new node<L>; // creating the new element to add
    newel->data = value;
    newel->next = m_head;
    m_head = el;
    m_size++;
  }

  void insert(L value, unsigned int position) {
    if(position == 0) {
      push_front(value);
    }

    else {
      node<L>* newel = new node<L>; // creating the new element to add
      newel->data = value;

      node<L>* prev = m_head; // prev is the previous node
      while(position > 1) {
        prev = prev->next;
        position--;
      }

      newel->next = prev->next;
      prev->next = newel;
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
      std::cout << element->data << std::endl;
      element = element->next;
    }
  }

  void destructor() {
    ;
  }

};
