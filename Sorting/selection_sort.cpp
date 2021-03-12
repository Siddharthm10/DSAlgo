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

void selctionSort(int *arr, int n){
    for(int i=n-1; i>=0; i--){
        int max=INT_MIN;
        int indexOfMax=0;
        for(int j=0; j<=i; j++){
            if(arr[j]>max){
                max = arr[j];
                indexOfMax = j;
            }
        }
        // cout<<arr[indexOfMax]<<endl;
        swap(arr[i], arr[indexOfMax]);
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
    selctionSort(arr,n);
    print(arr,n);
    
    return 0;
}