//"It's not a bug, It's a feature
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#define pi 3.1415926535
#define fu(i,n) for(int i=0; i<n; i++)
#define fd(i,n) for(int i=n; i>=0; i--)
#define ll long long int

using namespace std;

void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void merge_sorted_array(int* arr, int start, int middle, int end){
    // int i = start, j = middle+1;
    int n1 = middle-start+1;
    int n2 = end-middle;
    int arr1[n1], arr2[n2];
    
    for(int i=0; i<n1; i++)
        arr1[i] = arr[start + i];

    for(int j=0; j<n2; j++)
        arr2[j] = arr[middle+j+1];

    int i=0, j=0, k=start;
    // Traverse both array
    while(i<n1 && j<n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n1)
        arr[k++] = arr1[i++];
    

    // Store remaining elements of second array
    while (j < n2)
        arr[k++] = arr2[j++];
}


void merge_sort(int* arr, int start, int end){
    if(end>start){
        // cout<<"viable call ";
        int middle = start + (end-start)/2;
        merge_sort(arr, start, middle);
        merge_sort(arr, middle+1, end);
        merge_sorted_array(arr, start, middle, end);
    }
    else
        return;
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    print(arr, n);
    // merge_sorted_array(arr, 0, 2, 4);
    return 0;
}