//"It's not a bug, It's a feature
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

//LOMUTO PARTITION (last element becomes pivot)
int partition_l(int* arr, int start, int end){
    // initiating the variables
    int i=start-1; 
    int j=start;

    while(j<end){
        if(arr[j] <= arr[end]){
            i++; 
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

//HOARSE Partitioning (3 times faster)
int partition_h(int* arr, int start, int end){
    //initiating the variables
    int i=start-1;
    int j=end+1;
    int pivot = arr[start];

    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j) 
            return j;
        swap(arr[i], arr[j]);
        print(arr, 5);
        cout<<endl;
    }
}

void quick_sort(int* arr, int start, int end){
    if(start<end){
        // Here we are using lomuto partitioning
        int p = partition_h(arr, start, end);
        quick_sort(arr, start, p);
        quick_sort(arr, p+1, end);
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
    quick_sort(arr, 0, n-1);
    print(arr, n);
    // merge_sorted_array(arr, 0, 2, 4);
    return 0;
}