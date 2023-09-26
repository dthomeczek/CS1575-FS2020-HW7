// Declare your templated heap class here
//  The actual implementation should go into MyHeap.hpp
// Hint: if you are having a hard time figuring out how to start, look at the
//  past assignments and the example lecture code
// Reference:
//  http://en.cppreference.com/w/cpp/container/priority_queue

/* You will need to implement the following for MyHeap:
 *   1.   default constructor - starts with an empty array
 *   2.   parameterized constructor - takes two parameters, one templated array,
 *          and an integer size of the array.
 *          The constructor should build the internal heap using the heapify
 *          operation we learned. Note the syntax of this constructor differs
 *          from the std:: constructor
 *   3.   copy constructor
 *   4.   destuctor
 *   5.   operator =
 *   6.   top
 *   7.   pop
 *   8.   push
 *   9.   empty
 *   10.  size
 *   others: any additional internal functions that are needed or desired
 *             (i.e. reserve, shrink_to_fit, build_heap (heapify), sift_down(),
 *             etc.)
 *
 * Note 1:
 *  The behavior, return types, and parameters of the top, pop, push, empty,
 *  and size functions should be congruent with those of the std::priority_queue
 *
 * Note 2:
 *  Don't forget the get_identity function
 */
#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void get_identity(std::string &my_id);

template <typename T>
class MyHeap
{
    private:

        T *Heap;
        int m_size;
        int NumElems;

    public:

        MyHeap();

        MyHeap(T *arr, int s);

        MyHeap(const MyHeap<T> &source);

        ~MyHeap();

        MyHeap<T> & operator=(const MyHeap &source);

        T & top();

        void pop();

        void push(const T &element);

        void siftDown(int i);

        bool empty();

        int size();

        int sz();

        int leftChild(int pos);

        int rightChild(int pos);

        int parent(int pos);

        bool isLeaf(int pos);

        void buildHeap();

        void swap(T *arr, int firstInd, int secondInd);

        void reserve(int newSize);
        
        void shrinkToFit();
};

#include "MyHeap.hpp"

#endif