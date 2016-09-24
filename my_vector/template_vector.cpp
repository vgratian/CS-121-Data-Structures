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

        void push_back(T e) {
            if(m_size+1>m_capacity) {
                resize();
                push_back(e);
            }
            else {
                m_array[m_size] = e;
                m_size++;
            }
        }

        void insert(T element, int position) {
            if(m_size+1>m_capacity) {
                for(int i=m_size; i != position; i--) {
                    m_array[i] = m_array[i-1];
                }
                m_array[position] = element;
            }
        }

        void resize() {
            cout << "m_capacity was: " << m_capacity << ", now: ";
            m_capacity *= 2;
            cout << m_capacity << endl;
            T* temp = new T(m_capacity);
            for(int i=0; i<m_size; i++) {
                temp[i] = m_array[i];
            }
            delete[] m_array; // print m_array should still work??
            m_array = temp;
        }

        void remove() {}

        void set() {}

        void get() {}

        void push_back() {}

        void print(){
            cout << "m_size: " << m_size << endl;
            for(int i=0; i<m_size; i++) {
                cout << m_array[i] << endl;
            }
        }

        void set_size(T size) {
            m_size = size;
        }
};

int main() {
    my_vector<int> v;
    v.print();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.print();

    return 0;
}


/*
int array[10]
int* array = new int(x)
*/
