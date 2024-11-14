# queue_ds - Circular Queue Implementation

## Overview

The `queue_ds` class is a template-based implementation of a circular queue data structure. It supports standard queue operations such as `enqueue`, `dequeue`, `peekFront`, and `clear`. Additionally, it automatically resizes when the queue is full, providing dynamic growth to accommodate more elements.

## Table of Contents
- [Class: queue_ds<T>](#class-queueds)
  - [Private Member Variables](#private-member-variables)
  - [Private Member Functions](#private-member-functions)
  - [Public Member Functions](#public-member-functions)
- [Example Usage](#example-usage)
- [Function Details](#function-details)
  - [enqueue(const T& val)](#enqueueconst-t-val)
  - [dequeue()](#dequeue)
  - [peekFront()](#peekfront)
  - [print()](#print)
  - [clear()](#clear)
- [Error Handling](#error-handling)
- [Summary](#summary)

## Class: `queue_ds<T>`

This class represents a circular queue where `T` is the data type of the elements being stored in the queue.

### Private Member Variables:
- `T* arr`: A dynamic array used to store the queue elements.
- `int size`: The current number of elements in the queue.
- `int capacity`: The maximum number of elements the queue can hold before resizing.
- `int front`: The index of the front element in the queue.
- `int back`: The index of the back element in the queue.

### Private Member Functions:
- `bool isEmpty() const`: Returns `true` if the queue is empty (i.e., `size == 0`), otherwise `false`.
- `bool isFull() const`: Returns `true` if the queue is full (i.e., `size == capacity`), otherwise `false`.
- `void resize(size_t newCapacity)`: Resizes the queue array to a new capacity. This function is called when the queue is full. It copies the elements to the new array, reindexes them, and deletes the old array.

### Public Member Functions:
- **Constructor**: `queue_ds(int cap=5)`
  - Initializes the queue with a default capacity of 5 or a custom value provided as `cap`. Sets `size` to 0, `front` to 0, and `back` to `-1`.
  
- **Destructor**: `~queue_ds()`
  - Cleans up and frees the dynamically allocated array.

- `void enqueue(const T& val)`
  - Adds an element `val` to the back of the queue. If the queue is full, it resizes the queue to accommodate more elements.

- `void dequeue()`
  - Removes the front element from the queue. If the queue is empty, it prints an error message and does nothing.

- `T& peekFront() const`
  - Returns a reference to the front element without removing it from the queue. Throws an error if the queue is empty.

- `void print() const`
  - Prints the current elements in the queue in order from front to back. If the queue is empty, it prints "empty queue."

- `void clear()`
  - Clears all elements in the queue by resetting the `size`, `front`, and `back` values.

---

## Example Usage

```cpp
#include <iostream>
#include "queue_ds.h"

int main() {
    // Create a queue of integers with default capacity of 5
    queue_ds<int> q;

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Print the queue
    std::cout << "Queue after enqueue operations: ";
    q.print();

    // Peek at the front element
    std::cout << "Front element: " << q.peekFront() << std::endl;

    // Dequeue an element
    q.dequeue();

    // Print the queue after dequeue
    std::cout << "Queue after dequeue: ";
    q.print();

    // Enqueue more elements to see resizing in action
    q.enqueue(60);
    q.enqueue(70);

    std::cout << "Queue after more enqueues: ";
    q.print();

    // Clear the queue
    q.clear();
    std::cout << "Queue after clearing: ";
    q.print();

    return 0;
}
