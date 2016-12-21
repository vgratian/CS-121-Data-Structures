#include <iostream>
#include "main.h"
using namespace std;

/*.
Sorts an array of integers using the Bubble Sort algorithm
*/

int* sort_array(int arr[], int arr_size) {

    int size = arr_size;

    for(int k=1; k<size; size--) {

        for(int i=1; i<size; i++) {
            if(arr[i-1] > arr[i]) {
                swap(&arr[i-1], &arr[i]);
            }
        }
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
