// This is for performing the search option recursively.

int search(Node *head, int x){
    if(head==NULL) return -1;
    if(head->data==x)
        return 1;
    else{
        int res = search(head->next, x);
        if(res==-1) return -1;
        else return (res+1);
    }
}