#include <iostream>
using namespace std;

// NOT FINISHED........................!!!!!!!!!!!!!!!


void print_arr(int arr[]){
    int size = sizeof(*arr);
    cout << "size: " << size << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << endl;
    }
}

/*
int* merge(int arr_1[], int arr_2[]) {
    int size = sizeof(arr_1) + sizeof(arr_2);
    int* arr_temp = new int[size];

    while(sizeof(*arr_1)>0 && sizeof(*arr_2)>0) {
        if(arr_1[0] > arr_2[0]) {
            arr_temp.push_back(arr_2[0]);
            delete[] arr_2;
        }
        else {
            arr_temp.push_back(arr_2[0]);
            delete[] arr_1;
        }
    }

    return arr_temp;
}
*/

void merge_sort(int arr[]) {
    int n = sizeof(*arr);               //cout << "n: " << n << endl;
    if(n==0) {}
    else {
        cout << "size arr (n): " << n << endl;
        int arr_1[2];
        int arr_2[2];

        print_arr(arr);
        cout << "size arr_1: " << sizeof(*arr_1) << endl;
        cout << "size arr_2: " << sizeof(*arr_2) << endl;
        /*
        for(int i=0; i<n/2; i++) {
            arr_1[i] == arr[i];
        }

        for(int i=n/2; i<n; i++) {
            arr_2[i-(n/2)] = arr[i];
        } */
        //copy(arr+0, arr+((n/2)-1), arr_1);
        //copy(arr+(n/2), arr+(n-1), arr_2);

        print_arr(arr_1);
        print_arr(arr_2);
        //merge_sort(arr_1);
        //merge_sort(arr_2);

        //return merge(arr_1, arr_2);
    }
}


int main()  {

    int size = 4;
    int unsorted[size] = {9, 4, 1, 3};

    merge_sort(unsorted);
    return 0;
}
