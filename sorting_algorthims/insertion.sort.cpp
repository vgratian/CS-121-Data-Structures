#include <iostream>
#include "main.h"
using namespace std;

/*.
Sorts an array of integers using the Insertion algorithm
*/

int* sort_array(int arr[], int size, int unsorted=1) { // remember: size is actually "--size"

    if(unsorted==size) {
        return arr;
    }
    else {
        int next_element = arr[unsorted];
        int j = unsorted;

        while(j>0 && next_element<arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = next_element;
        sort_array(arr, size, ++unsorted);
    }
}

int main()
{
    int size=5;
    //int unsorted[size] = {9, 4, 2, 1, 3};     // փորձերի համար (որ անընդհատ ձեռքով չմուտքագրես)
    int unsorted[size];
    input_to_array(unsorted, size);

    cout << "unsorted array: " << endl;
    print_array(unsorted, size);
    cout << endl;

    int *sorted = sort_array(unsorted, size);

    cout << endl << "sorted array: " << endl;
    print_array(sorted, size);
}
