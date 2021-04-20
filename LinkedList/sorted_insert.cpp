#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* sorted_insert(Node* head, int x){
    Node* newNode = new Node(x);
    Node* temp = head;
    if(head==NULL){
        head = newNode;
        return head;
    }
    //Inserting at start if possible
    if(temp->data>x){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp->next!=NULL && temp->next->data<x){
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(8);
    int x;
    cin>>x;
    head = sorted_insert(head, x);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}