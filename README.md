# Homework #7

This was the seventh coding assignment for the Fall 2020 CS1575 (Data Structures) course. The purpose of this code was designed around priority queues and max-heap sorting.

# Information From Assignment README

For this homework assignment (contains two parts), you will implement a priority queue ADT using a MAX-Heap data structure.
  * http://en.cppreference.com/w/cpp/container/priority_queue

### Part (a)
You will implement the majority of the priority queue functions in the MyHeap class. Follow the instructions and specifications in `MyHeap.h` CAREFULLY. The behavior and specifications of some of the common priority queue functions (i.e. push() and pop()) should be congruent with those of the std::priority_queue.

#### Critical!!
You WILL need to have internal functions in MyHeap to **dynamically reserve** more space for your array if it *fills up*, and if it becomes less than *1/4 full*, to **shrink** the array size to fit.

### Part (b)
Next, you will need to build two functions:
  * `my_is_sorted()`
    * reference: http://en.cppreference.com/w/cpp/algorithm/is_sorted
  * `my_sort()`
    * reference: http://en.cppreference.com/w/cpp/algorithm/sort

Practically, you can use any sorting algorithm to implement my_sort(). However, for this assignment, it is REQUIRED and would be easy for you to use the heap operations to implement **HeapSort**.

**Note**: The sort functions will be much simpler (and different than) the std:: versions:
  * my_sort() should take two parameters --- a templated array, and an integer representing the size of the array. The return type should be *void*. The array that is passed in should then be sorted by the function. Also, **very important**, the final sorted array  should be **max-first** (non-ascending order), which is DIFFERENT than the in-class examples of HeapSort.

  * my_is_sorted() should take the same two parameters as my_sort(), and returns a *bool* --- true if the array is sorted max-first, and false if not.
