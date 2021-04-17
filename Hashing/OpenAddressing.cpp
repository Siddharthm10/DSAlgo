//linear probing
#include <bits/stdc++.h>
#include <list>
#include <iostream>
using namespace std;

struct MyHash {
    int* arr;
    int cap, size;
    MyHash(int c){
        cap = c;
        size = 0;
        for(int i=0; i<cap; i++){
            arr[i] = -1;
        }
    }

    int hash(int key){
        return key%cap;
    }

    bool search(int key){
        int h = hash(key);
        int i = h;
        while(arr[i]!=-1){
            if(arr[i]==key){
                return true;
            }
            i = (i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
    
    bool insert(int key){
        if(size==cap) return false;
        int i = hash(key);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key){
            i = (i+1)%cap;
        }
        if(arr[i]==key){
            return false;
        }else{
            arr[i] = key;
            size++;
            return true;
        }
    } 
    bool erase(int key){
        int h = hash(key);
        int i = h;
        while(arr[h]!=-1){
            if(arr[i]==key){
                arr[i] = -2;
                return true;
            }
            i = (i+1)%cap;
            if(i==h) return false;
        }
        return false;
    }
};

/* 
How to handle situation when -1 and -2 are actually part of our input keys;
IN actual implementations actual values are not required.
-1 is replaced by NULL
for deleted node we create a dummy node and input the reference to those dummy node
instead of -2
*/