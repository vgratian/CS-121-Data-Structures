#include <iostream>
#include "main.h"
using namespace std;

/*.
Sorts an array of integers using the Bubble Sort algorithm
*/

int* sort_array(int arr[], int size)
{
    for(int i=size; i>1; i--)
    {
        for(int j=1; j<i; j++)
        {
            if(arr[j-1] > arr[j])
            {
                swap(&arr[j], &arr[j-1]);
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
