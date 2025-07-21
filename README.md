# 🧾 Frankainstain Doubly Linked List Class in C++

This project implements a custom doubly linked `List` class in C++, offering flexible insertion, deletion, access, and traversal functionality. The list supports bidirectional iterators, reverse iterators, ascending/descending/multi-mode traversal, and STL-like operations, that's why it is called Frankainstain.

---

## 📁 Features

✅ Doubly linked list with rich iterator support  
✅ Copy/move constructors and assignments  
✅ Bidirectional and reverse iterators  
✅ Multi-mode traversal with `multi_iterator`  
✅ Insertion and erasure by position or range  
✅ Access front, back, min, max elements  
✅ Comparison and arithmetic operators  
✅ Custom `display` functions  

---

## 🧩 Class Overview

### Constructors
- `List()`: default empty constructor  
- `List(size_t size)`: uninitialized list of `size`  
- `List(size_t size, const_reference init)`: initialized with `init`  
- `List(std::initializer_list<int>)`: initializer list  
- Copy and move constructors  
- Range constructor with template iterator

---

### 🧠 Key Methods

| Method                  | Description                                |
|------------------------|--------------------------------------------|
| `push_back(int)`       | Adds element at the end                    |
| `push_front(int)`      | Adds element at the front                  |
| `insert(index, value)` | Inserts at specific position               |
| `pop_back()`           | Removes last element                       |
| `pop_front()`          | Removes first element                      |
| `erase(pos)`           | Removes element by index                   |
| `erase(first, last)`   | Removes a range of elements                |
| `remove(value)`        | Removes first occurrence of value          |
| `resize(n)`            | Resizes to `n` elements                    |
| `clear()`              | Clears the list                            |
| `size()`               | Returns list size                          |
| `min()` / `max()`      | Returns min/max elements                   |
| `reveres()`            | Reverses the list                          |
| `get(index)`           | Access by index                            |

---

### 📐 Operators

- `==`, `!=`, `<`, `>`, `<=`, `>=`: comparison  
- `+`: concatenation of two lists  
- `[]`: indexed access  
- Assignment operators for copy, move, initializer list

---

### 🔁 Iterators

| Type                      | Direction | Notes                                      |
|---------------------------|-----------|--------------------------------------------|
| `iterator`                | Forward   | Mutable forward iterator                   |
| `const_iterator`          | Forward   | Immutable forward iterator                 |
| `reverse_iterator`        | Reverse   | Mutable reverse iterator                   |
| `const_reverse_iterator`  | Reverse   | Immutable reverse iterator                 |
| `asc_iterator`            | Ascending | Based on value order                       |
| `desc_iterator`           | Descending| Based on value order                       |
| `multi_iterator`          | Multi-mode| Mode-switchable iterator                   |
| `multi_reverse_iterator`  | Reverse + mode| Multi-mode in reverse                     |

---

### 🧪 Example Usage

```cpp
#include "List.h"

List myList = {4, 1, 9, 5};

myList.push_back(10);
myList.push_front(3);
myList.insert(2, 7);

std::cout << myList.front() << " to " << myList.back() << std::endl;

myList.display_inc();
myList.reveres();
myList.display_dec();

for (auto it = myList.begin(); it != myList.end(); ++it) {
    std::cout << *it << " ";
}
