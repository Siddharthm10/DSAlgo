#include <bits/stdc++.h>
#include <list>
using namespace std;

struct Node
{
    //Doubly linked list
    Node* prev;
    int value;
    Node* next;
};

struct MyHash
{
    int BUCKET;
    list<int> *table;
    MyHash(int b){BUCKET=b; table=new list<int>[BUCKET];};
    void insert(int key){
        int i = hash(key);
        table[i].push_back(key);
    };

    void del(int key){
        int i = hash(key);
        table[i].remove(key);   
    };
    bool search(int key){
        int i = hash(key);
        for(auto x:table[i]){
            if(x==key){
                return true;
            }
        }
        return false;
    };
    int hash(int key){return key%BUCKET;};
};
