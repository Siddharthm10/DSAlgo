---
tags: [C++, ds-algo]
title: Sorting
created: '2021-02-21T18:53:24.808Z'
modified: '2021-03-11T20:34:00.405Z'
---

# Sorting
**NOTE** - These are notes from the geeks for geeks Data Structures course.
These algos are used to sort data structures with random element access in constant time.(Arrays, Vectors, deque)
### Sorting in C++ STL
```
sort(arr,arr+n);
sort(vec.begin(), vec.end());
sort(deq.begin(), deq.end());
```
You can also give a third parameter for the sorting functionality to be used.
Example: `greater<int>` : sorts in decreasing order(By default it is set to `lower<int>`)
We can also give our own order for user defined datatype by defining our own comparision function.

> **Time complexity**: O(nlogn)
> **Algorithm Used**: Intro sort(Hybrid of Quick sort, Heap Sort, and Insertion sort)(=> That is when quick sort is doing bad partitioning(time taken>O(nlogn)) it uses heap sort, and when the heap size is too small it uses insertion sort.)


### Stability in sorting algorithms
By stability we mean that, if two items are same in the criteria they are to be compared, then they must appear in the order that they were placed in the original input array.
Stabling is only important when there are multiple fields and the other fields are to be sorted according to the sorting done on certain fields

> **Stable sorts**: Bubble sort, Insertion sort, Merge sort etc.
> **Unstable sorts**: Selection Sort, Quick sort, Heap sort etc.


### Bubble Sort:
Performs several bubble pass until the array is sorted.
In a bubble pass the adjacent elements are swapped, if found in a certain sorting order.
To know when to stop with every ith pass n-i elements should be sorted at the end of that respective pass.
- Stable

> **Time complexity**: O(n^2)
> **No. of Ops** : n(n-1)/2

### Selection Sort:
Finds the max element in the array -> swaps it with the last element.
Keeps doing this for all the objects one by one until the array is sorted.
- Basic idea for heap sort
- Not Stable
- In place Algorithm.

> **Time Complexity**: O(n^2) in all cases.
> **Feature**: This does the minimum memory writes. Can be preferred where memory writes are costly.

### Insertion Sort:
We start from the second element and we maintain the elements 0 to i-1 sorted.
i=1->n-1

**NOTE** : Use Insertion sort when the stack size based algorithms reach really small.
> **Time Complexity**: O(n^2) -> worst case , O(n)
> **Feature**: Best performance when the input size is small.

### Merge Sort:
It is a divide and conquer algorithm. It divides the array into two parts and then sorts the array and mergers them.
- It is a stable sorting algorithm. It is external Sorting.
- It is outperformed by QuickSort.

**Workflow**:
1. Check if there are more than 1 elements.
2. Find mid point of the array. ((r+l)/2)
3. apply recursive sorting for both halves
4. merge both arrays.

> **Time Complexity**: O(nlogn) :-> O(n) (merging) * O(logn) (for splitting from mid point)
> **Space Complexity**: O(n)

#### Merge two sorted arrays:
- Naive Approach : Create a new array with all the items in both arrays and then sort the array c. (O((m+n)log(m+n)))
- Better Approach : 
  Continous loop and keep comparing the last element to both upcoming elements and once the smaller array has ended. We can push the remaining part of the longer array to the output.
> **Time Complexity**: (O(m+n))

#### Partitioning Algorithms:
- Naive Approach: 
1. Creates array of sufficient size.
2. Copy all the smaller or equal to pivot element to a temp array.
3. Then after the pivot element we push the greater elements.

> **Space Complexity**: O(n)
> **Time Complexity**: O(n) But the traversal is happening 3 times

- Lomuto Partition: (requires one traversal)
1. if you see smaller element increase the window of smaller elements and swap that with the pivot. (i is increased, swap(ith wih jth))
2. You do nothing when you  visit a element greater than the pivot element.
3. In the end swap the pivot with i+1 th element.

- Hoare's Partition method(O(n) -> takes less number of comparisions.)
1. i = start-1 , j=end+1
2. We increment i and decrement j. Also we stop when they cross or meet each other.
3. Keep increment until you find the greater element.
4. Keep decrementing until you find smaller element.
5. Keep repeating the process
6. when i and j cross each other return j
7. swap if they havent crossed


