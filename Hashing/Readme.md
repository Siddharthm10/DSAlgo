# Hashing
Hashing is mainly used to implement dictionaries and sets. It is amazing because it provides constant time **search, insert, and delete** operations.

**NOTE**:The only thing to take care of is that the keys should be distinct.

It is not useful for:
1. Finding Closest value-----| In these AVL TREES or RED-BLACK TREES Can be used.
2. Sorted Data---------------|
3. Prefix Searching

### Applications of Hashing
1. Dictionaries
2. Databox Indexing
3. Cryptography
4. Caches
5. Symbol Tables in Compilers/Interpreters.
6. Getting data from Database <br>
ETC......


### Direct Address Table
This is table consisting of 1000 items or some specific amount of items. And it is an array in which all values are 0. All the values inserted are set as 1. deleted are set as 0.
Cons: 
- This doesnt contain letters and other datatypes.
- This has limited space
Pros:
- O(1) search, delete and insert time complexity.

### Concept of Hashing

```
(                 )                            0 [] 
(   Universe      )                            1 [] 
(       of        ) ----> Hash Function -----> 2 []
(      Keys       )       (takes values and converts them to small values i.e. index)
```

#### How Hash functions work?
- Should always map a large key to same small key
- Should generate values from 0 to m-1
- should be fast, O(1) for integer and O(len) for strings
- Should uniformly distribute large keys into Hash Table Slots

**NOTE** : Hash table size is propotional to the number of keys you are supposed to have.

### Collisions Handling:
Collision referst to the incident when two or more different elements after passing through a hash function end up in same memory space.

**NOTE**: BIRTHDAY PARADOX: It states that if there are 23 people in a room then there is a probability of 1/2 that two of the people have same birthday. With 70 people it reaches 99.9%. (This is how serious collision problem is!)

If you know keys in advance, then we can perform PERFECT HASHING.
If you don't know the keys, then we use one of the following:
- Chaining
- Open Addressing
  - Linear Probling
  - Quadritic Probing
  - Double Hashing
 

#### Chaining
Here the hash table is an array of linked list headers. Whenever a collision happens we insert the element at the end of those headers.

##### Performance:
m = No. of slots in the hash table.
n = No. of keys to be inserted.
Load Factor(how big you want the hash table to be, Ideally -> small) = n/m
Expected Chain Length = Load factor
Expected Time to search = O(1 + Load Factor)

##### Different data str for storing chains
- Linked list -> Search = O(l), Delete O(l), Insert O(l) : Its not cache Friendly; uses extra space
- Dynamic Sized Arrays (Vectors) (time complexity is same); Uses less space, Cache friendly
- Self Balancing BST-> O(logL); Not cache friendly (This is preffered)


#### Open Addressing
> Condition: No. of slots in hash table >= No. of keys to be inserted

- It is cache friendly.
- It is done in three ways:
  - Linear Probing
  - Quadritic probing
  - Double hashing

##### Linear Probing:
On collision, we linearly search for next empty slot. If u search from the last slot, linear probing causes the hashing process to search for the next element circularly.

Search/insert function: 
- We compute hash function
- we go to that index and compare
- If found return true;
- else linearly search until finding that key or facing an empty slot
- if the hashmap is full, traverse through whole map once.

Delete function:
- If we directly delete this will create additional empty spaces in between causing misfunctional search and insert functions
- So when deleting an element, we mark the slot as deleted not empty.

**Problem with Linear probing**:
When we saw linear probing we saw that whenever collision occured it moved linearly forward to the next empty cell making all the operations on this costly. This phenomena is called cluster formation.

**Solution**:
- Quadritic Probing:
    - Hash(key, i) = (h(key)+i^2)%m
    - Requirements for it to work:
      - Load factor < 0.5
      - m is a prime
- Double Hashing:
    - Hash(key, i) = (h1(key) + i*h2(key))%m

##### Double Hashing:
Here two hash functions are used. 
example : Hash(key, i) = (h1(key) + i*h2(key))%m
- Distributes key more uniformly
- No clustering
- if h2(key) is relatively prime to m, then it always find a free slot if there is one.
**NOTE:** The second hash function should never return 0... Otherwise we'll keep looking at the same place forever.


```
void doubleHashingInsert(key){
  if(table is full)
    return error;
  probe = h1(key), offset = h2(key);
  while(table[probe] is occupied){
    probe = (probe + offset)%m;
  }
  table[probe] = key;
}
```

**Performance Analysis of Search:**
Load Factor = n/m(should be <=1)
Assumption: Every probe sequence looks at a random location.
(1-alpha) Fracion of the table is empty.
Expected number of probes: 1/(1-alpha)
In case of chaining alpha->1, number of comparision tends to infinite

### Differences:
| Chaining| Open Addressing|
|---------|----------------|
|Hash never fills| Table may become full and resizing becomes mandatory|
|Less sensitive to hash function| Exxtra care required for clustering|
|Poor Cache Performance| Cache friendly|
|Extra space for links| Extra space might be needed to acheive some performance as chaining|


## Unordered Set in STL

Syntax - `unordered_set<int> s`

### Arbitrary methods:
- insert
- begin
- end
- size
- clear
- find -> Returns iterator to that element.
- erase -> either you can erase using value `s.erase(val)`, or using iterator `s.erase(itr)`, or to remove a set of elements `erase(s.begin(), s.end())`

### Properties
- Order is not preserved.

### Internal Working
- Time complexity of search, insert and delete O(1) under the assumption that hashing is perfect.


## Unordered Map in STL
- Used to store key, value points
- Uses Hashing
- No order of Keys
- order is not maintained and depends on the internal working of the hashing
- Syntax: `unordered_map<string, int> m`

### Arbitrary Methods
- insert
- first: `itr->first` returns key of that key,value pair
- second: `itr->second` returns value of that key, value pair
- find: `m.find("key")` returns a key, value pair


