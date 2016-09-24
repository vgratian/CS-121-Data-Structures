#pragma once
#include <iostream>
using namespace std;

void input_to_array(int arr[], int size)
{
    cout << "please enter "<< size << " numbers" << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    return;
}

void print_array(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}
