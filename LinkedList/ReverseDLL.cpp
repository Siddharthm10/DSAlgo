

Node* reverseDll(Node* head){
	if(head==NULL||head->next==NULL) return head;
	Node* next = NULL;
	Node* curr = head;
	Node* temp = NULL;
	while(curr!=NULL){
		next = curr->next;
		temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;
		curr = next;
	}
	return curr;
}