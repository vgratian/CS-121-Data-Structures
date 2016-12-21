/*.
Sorts an array of integers using the Merge Sort algorithm
TODO: FIX BUG, probably in lines 21-24
*/

void merge(int *main_arr, int size, int *left_arr, int *right_arr) {
  int k, j, i;
  k = 0; j = 0; i = 0;

  while(i < (size/2) && j < (size/2) {
    if(left_arr[i] < right_arr[j])
      main_arr[k++] = left_arr[i++];
    else
      main_arr[k++] = right_arr[j++];
  }

  while(i < (size/2))
    main_arr[k++] = left_arr[i++];
  while(j < (size/2))
    main_arr[k++] = right_arr[j++];
}

void merge_sort(int *arr, int size) {
    if(size < 2)
    return;

  int mid = size/2;
  int *left;
  left = new int[mid];
  int *right;
  right = new int[size-mid];

  for(int i=0; i<mid; i++)
    left[i] = arr[i];

  for(int i=mid; i<size; i++)
    right[(i-mid)] = arr[i];

  merge_sort(left, mid);
  merge_sort(right, size-mid);

  merge(arr, size, left, right);
}
