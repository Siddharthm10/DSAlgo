struct Node
{
	int data;
	Node* next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

class stack
{
private:
	Node* head = NULL;
public:
	stack();
	~stack();
	void push(int x){
		Node* temp = new Node(x);
		temp->next = head;
		head = temp;
	}

	int pop(){
		if(head==NULL){
			return NULL;
		}

		int res = head->data;
		Node *temp = head;
		head = head->next;
		delete(temp);
		return res;
	}

	int top(){
		if(head==NULL)
			return ;
		return head->data;
	}

	int size(){
		int counter=0;
		Node* temp=head;
		while(temp){
			counter++;
			temp = temp->next;
		}
		return counter;
	}
};