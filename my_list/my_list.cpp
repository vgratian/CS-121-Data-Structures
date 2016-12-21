template <class N>
class node {
public:
  N data;
  node* next;
};

template <class L>
class List {
protected:
  node<L>* m_head;
  node<L>* m_tail;
  unsigned int m_size;

public:
  List();
  bool is_empty();
  unsigned int get_size();
  void push_front(L value);
  void push_back(L value);
  void insert(L value, unsigned int position);
  void remove(unsigned int position);
  void print();
  L get_data(unsigned int position);

};

template <class L>
List<L>::List() {
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}

template <class L>
bool List<L>::is_empty() {
  if(m_size == 0)
    return true;
  return false;
}

template <class L>
unsigned int List<L>::get_size() {
  return m_size;
}

template <class L>
void List<L>::push_front(L value) {
  node<L>* newel = new node<L>; // creating the new element to add
  newel->data = value;
  newel->next = m_head;   // this is either NULL or pointer to first element
  m_head = newel;
  if(m_size == 0)         // if list was empty tail should point to newel
    m_tail = newel;
  m_size++;
}

template <class L>
void List<L>::push_back(L value) {
  if(m_size == 0) {
    push_front(value);
  }
  else {
    node<L>* newel = new node<L>; // creating the new element to add
    newel->data = value;
    newel->next = NULL;
    node<L>* last = m_tail;       // identifing last element in the list
    m_tail = newel;
    last->next = newel;
    m_size++;
  }
}

template <class L>
void List<L>::insert(L value, unsigned int position) {
  if(position == 0)
    push_front(value);

  else if(position == m_size)
    push_back(value);

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

template <class L>
void List<L>::remove(unsigned int position) {
  if(m_size == 0) // if list is empty do nothing
    ;
  else {
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
}

template <class L>
void List<L>::print() {
  node<L>* element = m_head; // element == each element in the list
  while(element != NULL) {
    std::cout << element->data << std::endl;
    element = element->next;
  }
}

template <class L>
L List<L>::get_data(unsigned int position) {
  node<L>* el;

  if(position == 0)
    el = m_head;

  else if(position == -1)
    el = m_tail;

  // TODO: else for other positions

  return el->data;
}
