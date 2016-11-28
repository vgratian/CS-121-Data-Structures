
template <class N>
class node {
public:
  N data;
  node* next;
};

template <class Q>
class my_queue {
protected:
  node<Q>* m_head;
  node<Q>* m_tail;
  unsigned int m_size;

public:
  my_queue() {
    m_head = NULL;
    m_size = 0;
  }

  bool is_empty() {
    if(m_size == 0)
      return true;
    return false;
  }

  int get_size() {
    return m_size;
  }

  void enqueue(Q value) {

    node<Q>* newel = new node<Q>; // creating the new element
    newel->data = value;
    newel->next = NULL;

    if(m_size == 0) {
      m_head = newel;
      m_tail = newel;
    }

    else {
      node<Q>* last = m_tail;
      last->next = newel;
      m_tail = newel;
    }

    m_size++;
  }


  Q dequeue() { // needs exception handling if m_size == 0
    Q value;

    node<Q>* el = m_head;
    value = el->data;
    m_head = el->next;
    delete el;
    m_size--;

    return value;
  }

  Q get_front() {
    node<Q>* el = m_head;
    return el->data;
  }

  void print() {
    node<Q>* element = m_head; // element == each element in the list
    while(element != NULL) {
      std::cout << element->data << std::endl;
      element = element->next;
    }
  }

};
