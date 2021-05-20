# Linked List
- Linear data structure
- Not stored in continuous memory locations
- Use extra memory to store the memory location of the next element
- Last Node points to NULL

#### Advantages:
- Insert & Delete anywhere 
- No need of pre-allocation

### Definition:
```
struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
}
```

- To define a new node, we can use the constructor:
`Node *head = new Node(10);`


# Circular Linked List
- You can traverse the whole list from any node
- We can insert at both ends at constant time complexity
- Implementing algorithms like Round Robin

### Disadv
- Insertion deletion and traversal becomes slightly complex.

```
Problem Statement: Add element to the begining of the CLL
Solution:
	Add the element at the first position
	And then swap the values of the head & the first position
```
```
Probelm Statement: Add element to the end of the CLL
Solution:
	Do the same as above
	Change the head (XD)
```


# Doubly Linked List
### Adv
- Can be traversed in both direction
- We can delete the given node in O(1) time
- We can insert/delete a node before a given node in O(1) time

### Disadv
- Extra space used
- The code becomes more complex as the pointer has to be maintained everywhere



### Definition:
```
struct Node{
	int data;
	Node* prev;
	Node *next;
	Node(int x){
		data=x;
		next=prev=NULL;
	}
}
```
