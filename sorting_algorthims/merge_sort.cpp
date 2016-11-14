#include <iostream>
#include "main.h"
using namespace std;


void merge(int *main_arr, int size, int *left_arr, int *right_arr) {
  cout << "merge ! " << endl;
  int k, j, i;
  k = 0; j = 0; i = 0;

  while(i < (size/2) && j < (size/2)) {
    if(left_arr[i] < right_arr[j])
      main_arr[k++] = left_arr[i++];
    else
      main_arr[k++] = right_arr[j++];
  }

  while(i < (size/2))
    main_arr[k++] = left_arr[i++];
  while(j < (size/2))
    main_arr[k++] = right_arr[j++];

    print_array(main_arr, 9);
}

void mergesort(int *arr, int size) {
    if(size < 2)
    return;

  cout << "split ! " << endl;

  int mid = size/2;
  int *left;
  left = new int[mid];
  int *right;
  right = new int[size-mid];

  for(int i=0; i<mid; i++)
    left[i] = arr[i];

  for(int i=mid; i<size; i++)
    right[(i-mid)] = arr[i];

  print_array(left, mid);
  print_array(right, size-mid);

  mergesort(left, mid);
  mergesort(right, size-mid);

  merge(arr, size, left, right);
}

int main() {

  int size = 9;
  int unsorted[size] = {2, 4, 7, 20, 1, 3, 5, 12, 6};

  print_array(unsorted, size);
  mergesort(unsorted, size);

//  print_array(unsorted, size);
  cout << "it works...!" << endl;

  return 0;
}
