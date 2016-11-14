#include <iostream>
#include "main.h"
using namespace std;

/*.
Sorts an array of integers using the Selection Sort algorithm
*/

int* sort_array(int arr[], int size) {

    int size = arr_size;

    for(int k=0; k<size; size--) {
        int largest = 0;                            // here we'll keep the index of the largest element

        for(int i=1; i<size; i++) {             // find the largst element
            if(arr[i] > arr[largest]) {
                largest = i;
            }
        }

        swap(&arr[size-1], &arr[largest]);      // swap largest element and last element
    }

    return arr;
}

int main()
{
    int size=5;
    int unsorted[size];

    input_to_array(unsorted, size);

    cout << "unsorted array: " << endl;
    print_array(unsorted, size);

    int *sorted = sort_array(unsorted, size);

    cout << "sorted array: " << endl;
    print_array(sorted, size);
}
