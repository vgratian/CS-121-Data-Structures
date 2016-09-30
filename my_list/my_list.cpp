#include <iostream>
using namespace std;
// destructor
// operator overloading
// stack: last in, first out    > push, pop, is_empty, get_size, get_top, print
// queue: first in, first out

template <class T>
class node {
public:
    T data;
    node* next;
};

template <class P>
class my_list {
public:
    node<P>* m_head;
    node<P>* m_end;
    int m_size;

    my_list() {
        m_head = NULL;
        m_end = NULL;
        m_size = 0;
    }

    void size() {
        //cout << "SIZE" << endl;
        cout << m_size << endl;
    }

    void print() {
        node<P>* e = m_head;            // each element in the list
            cout << e->data << endl;
        if(m_size > 1) {
            e = m_head->next;
            cout << e->data << endl;
        }
    }

        //while(m_size > 0 && e->next != NULL) {
        //    int* data = &e->data;
        //    cout << &data << endl;
        //    e = e->next;
        //}

        /*cout << "PRINT" << endl;

        if(m_head != NULL) {
            cout << m_head->data << endl;

            while(m_head->next != NULL) {
                cout << "    WHILE" << endl;

                cout << &m_head << endl;
            }
        }
    */

    void push_front(P value) {
        cout << "PUSH_FRONT" << endl;

        node<P>* n =  new node<P>;
        n->data = value;
        n->next = NULL;
        m_head = n;
        m_size++;
    }
/*
    insert (P, v)
    if first element : push_front
    else:
        node<P>* temp = new node
        node -> data = v
        node* n = get(P-1) ??              // find position
        temp->next = n->next
        n->next = temp;

node* get (unsigned int P)
    node* temp = head
    while(temp != Null & i != p)
    i++
    temp = temp->next
return temp;

void destructor() {

}
*/
};

int main() {

    my_list<int> velocities;
    velocities.size();
    //velocities.print();

    velocities.push_front(42);
    velocities.push_front(1984);
    velocities.push_front(23);
    velocities.size();

    velocities.print();

    //cout << velocities.m_head->data << endl;

    return 0;
}
