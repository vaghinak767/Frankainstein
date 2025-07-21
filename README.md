# 🧾 Frankainstain Doubly Linked List Class in C++

This project implements a custom doubly linked `List` class in C++, which provides an efficient and flexible container for managing a sequence of integers. The list supports a wide variety of operations, including insertion, deletion, searching, and traversal, using both forward and reverse iterators. This class mimics a basic implementation of a linked list while offering custom features like multi-mode traversal, that's why it is called Frankainstain.

---

## 📁 Features

✅ **Dynamic List Management**: The list can grow and shrink dynamically based on user needs.  
✅ **Iterator Support**: Full support for bidirectional, reverse, ascending, descending, and multi-mode iterators.  
✅ **Memory Management**: Proper memory management with the use of dynamic memory allocation and custom destructors.  
✅ **STL-like Operations**: Implements comparison, addition, and other common list operations.  
✅ **Custom Display**: Display list contents in ascending or descending order.  
✅ **Multi-mode Iterators**: Supports advanced iterators like `multi_iterator` for flexible traversal modes.

---

## 🧩 Class Overview

### Constructors

- **`List()`**: Default constructor that initializes an empty list.
  
- **`List(size_t size)`**: Constructor that creates a list of a specified size, but the elements are uninitialized.

- **`List(size_t size, const_reference init)`**: Initializes the list with `size` elements, all set to the value `init`.

- **`List(std::initializer_list<int> init)`**: Initializes the list with the values provided in the initializer list.

- **`List(input_iterator f, input_iterator l)`**: A range constructor that initializes the list by iterating over a specified range of iterators.

- **Copy and Move Constructors**: Support for copying and transferring ownership of list data.

---

### 🔧 Key Methods

| Method                      | Description                                    |
|----------------------------|------------------------------------------------|
| **`push_back(int)`**        | Adds an element at the end of the list.        |
| **`push_front(int)`**       | Adds an element at the front of the list.      |
| **`insert(int index, int data)`** | Inserts an element at a specific position in the list. |
| **`pop_back()`**            | Removes the last element from the list.        |
| **`pop_front()`**           | Removes the first element from the list.       |
| **`erase(int pos)`**        | Removes an element at the specified position.  |
| **`erase(int first, int last)`** | Removes a range of elements between `first` and `last`. |
| **`remove(int el)`**        | Removes the first occurrence of element `el`.  |
| **`resize(size_type s)`**   | Resizes the list to `s` elements. The new elements are initialized to the default value. |
| **`clear()`**               | Removes all elements from the list, deallocating memory. |
| **`size()`**                | Returns the number of elements in the list.    |
| **`min()` / `max()`**       | Returns the minimum/maximum element in the list. |
| **`reverse()`**             | Reverses the order of the list.                |
| **`display_inc()`**         | Displays the list elements in ascending order. |
| **`display_dec()`**         | Displays the list elements in descending order. |
| **`get(int index)`**        | Returns the element at a specified index.      |

---

### 🧑‍💻 Iterator Support

This class offers multiple types of iterators for traversing the list:

| Type                        | Direction  | Description                            |
|-----------------------------|------------|----------------------------------------|
| **`iterator`**               | Forward    | Mutable forward iterator. Allows modification of elements. |
| **`const_iterator`**         | Forward    | Immutable forward iterator. Can't modify elements. |
| **`reverse_iterator`**       | Reverse    | Mutable reverse iterator. Allows modification of elements while traversing the list in reverse. |
| **`const_reverse_iterator`** | Reverse    | Immutable reverse iterator. |
| **`asc_iterator`**           | Ascending  | Traverses the list in ascending order based on element value. |
| **`desc_iterator`**          | Descending | Traverses the list in descending order based on element value. |
| **`multi_iterator`**         | Multi-mode | Special iterator with mode switching, enabling flexible traversals. |
| **`multi_reverse_iterator`** | Reverse & Multi-mode | A reverse iterator with mode switching. |

### 🧑‍🔧 Custom Iterators

- The `base_iterator` class is the foundation for all iterator types. It holds the raw pointer (`Node* ptr`) to the current element.
  
- **`const_iterator`, `iterator`, `const_reverse_iterator`, `reverse_iterator`**: These iterators extend the `base_iterator` and add custom functionality to access or modify the elements in forward or reverse order.
  
- **`asc_iterator`, `desc_iterator`, `multi_iterator`, `multi_reverse_iterator`**: Specialized iterators that allow the list to be traversed in various ways — either based on value order (ascending or descending) or by switching modes.

---

### 🧩 Additional Functionality

- **Element Access**: The class supports random access via the `operator[]`, allowing you to access list elements by index.

- **Comparison Operators**: You can compare two lists using `==`, `!=`, `<`, `>`, `<=`, and `>=` operators, enabling easy list comparison.

- **Memory Management**: The `clear()` function safely deallocates memory and ensures no memory leaks occur when removing elements or clearing the entire list.

---

### 🧪 Example Usage

```cpp
#include "List.h"

List myList = {10, 20, 30, 40};

// Add elements to the list
myList.push_back(50);
myList.push_front(5);

// Display elements in ascending order
myList.display_inc();

// Remove elements by index
myList.erase(1);  // Removes element at index 1

// Traverse with custom iterator
for (auto it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << " ";
}

// Reverse the list
myList.reverse();
myList.display_dec();

