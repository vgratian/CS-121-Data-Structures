#include <iostream>
#include "main.h"
using namespace std;

/*.
Sorts an array of integers using the Selection Sort algorithm
*/

int* sort_array(int arr[], int size)
{

    for(int i=size; i>1; i--)
    {
        int j = 0;
        int max = arr[j];                 // first element is condifitionally considered the largest

        for(int k=1; k<i; k++)
        {
            if(arr[k] > max)
            {
                max = arr[k];
                j = k;
            }
        }

        swap(&arr[i-1], &arr[j]);    // swap the element with largest integer and the last element
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
