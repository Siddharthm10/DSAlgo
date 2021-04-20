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

Node* reverseLL(Node* head){
    Node* nextNode = head->next;
    Node* currNode = head;
    Node* prevNode = NULL;
    while(nextNode!=NULL){
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        nextNode = nextNode->next;
    }
    currNode->next = prevNode;
    return currNode;
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->next = new Node(8);
    

    head = reverseLL(head);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}