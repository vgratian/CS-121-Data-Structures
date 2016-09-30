#include <iostream>
using namespace std;

template <class T>
class my_vector {
private:
    int m_capacity;
    int m_size;
    T* m_array;

public:
    my_vector() {
        m_capacity = 1;
        m_size = 0;
        m_array = new T[m_capacity];
    }

    void resize() {                             // doubles the size of capacity (not m_size!)
        m_capacity *= 2;
        T* temp = new T(m_capacity);
        for(int i=0; i<m_size; i++) {
            temp[i] = m_array[i];
        }
        delete[] m_array; // print m_array should still work?
        m_array = temp;
    }

    void push_back(T e) {                   // e == element
        if(m_size+1>m_capacity) {      // check if capacity is enough
            resize();
            push_back(e);
        }
        else {
            m_array[m_size] = e;
            m_size++;
        }
    }

    void insert(T e, int p) {                   // p == position
        if(m_size+1>m_capacity) {       // check if capacity is enough
            resize();
            insert(e, p);
        }
        else {
            for(int i=m_size; i > p; i--) {
                m_array[i] = m_array[i-1];
            }
            m_array[p] = e;
            m_size++;
        }
    }

    void remove(int p) {
        for(int i=p; i<m_size-1; i++) {
            m_array[i] = m_array[i+1];
        }
        m_array[m_size-1] = NULL;
        m_size--;
    }

    void set(T e, int p) {
        m_array[p] = e;
    }

    T get(int p) {
        return m_array[p];
    }

    int get_size() {
        return m_size;
    }

    void set_size(int new_size) {
        m_size = new_size;
    }

    void print(){
        cout << "m_size: " << m_size << endl;
        for(int i=0; i<m_size; i++) {
            cout << m_array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    my_vector<char> v;
    v.print();
    v.push_back('b');
    v.push_back('c');
    v.push_back('d');
    v.push_back('f');
    v.print();
    v.insert('a', 0);
    v.insert('e', 4);
    v.insert('g', 6);
    v.print();
    v.remove(0);
    v.remove(2);
    v.remove(4);
    v.print();

    return 0;
}


/*
int array[10]
int* array = new int(x)
*/
