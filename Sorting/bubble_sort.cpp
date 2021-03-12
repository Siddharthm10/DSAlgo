//"It's not a bug, It's a feature
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

void print(int* arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//naive 
void bubble_sort(int* arr, int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(arr[j-1]>arr[j])
                swap(arr[j], arr[j-1]);
        }
    }
}

//optimized
void bubble_sort_opt(int* arr, int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i-1; j++){
            if(arr[j-1]>arr[j])
                swap(arr[j], arr[j-1]);
        }
    }   
}

//optimized 2 -> early exit if the array is sorted.
void bubble_sort_opt(int* arr, int n){
    for(int i=0; i<n; i++){
        bool swapped = false;
        for(int j=1; j<n-i-1; j++){
            if(arr[j-1]>arr[j]){
                swap(arr[j], arr[j-1]);
                swapped=true;
            }  
        }
        if(swapped) break;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Before sorting: ";
    print(arr,n);
    cout<<"After sorting: ";
    bubble_sort(arr,n);
    print(arr,n);
    
    return 0;
}