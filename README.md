# DSA Library Management System

![Language](https://img.shields.io/badge/Language-C++-blue)
![Semester](https://img.shields.io/badge/Semester-3rd-orange)
![DSA](https://img.shields.io/badge/Concepts-DSA-yellow)

---

## Introduction
The **DSA Library Management System** is a C++ console-based program designed to manage books and students in a library using **linked lists** and other **data structure and algorithm concepts**. It allows users to add, display, sort, search, update, and delete books, as well as manage students and track book issuance and returns. The system demonstrates practical applications of **bubble sort**, **binary search**, and **linked lists** in a real-world scenario.

---

## Features
- **Add a new book**: Enter book ID, title, author, and publication year.  
- **Display all books**: View the list of all books in the library.  
- **Sort books by ID**: Uses **bubble sort** to arrange books in ascending order.  
- **Search a book**: Quick search using **binary search**.  
- **Update book details**: Modify title, author, or year of a book.  
- **Delete a book**: Remove a book from the system by ID.  
- **Add a student**: Enter roll number and name.  
- **Display all students**: View the list of all students.  
- **Issue book**: Assign a book to a student.  
- **Return book**: Mark a book as returned.  
- **Exit**: Close the program safely.

---

## Implementation
- **Programming Language**: C++  
- **Data Structures Used**: Linked Lists (for dynamic storage of books and students)  
- **Algorithms Used**: Bubble Sort (sorting books by ID), Binary Search (searching books efficiently)  
- **Classes**:  
  - `Book` – stores book details and pointer to next book  
  - `Student` – stores student details and pointer to next student  
  - `Book-List` – handles book operations  
  - `Student-List` – handles student operations  

The program is **menu-driven**, allowing users to select operations easily. Each functionality is implemented as a separate function to maintain modularity and readability.

---

## Future Enhancements
- Integrate a **database** for improved data management  
- Implement **user authentication** and role-based access  
- Add **fine calculation** for overdue books  
- Develop a **reservation system** for students  
- Generate **reports and statistics** on library usage  

---

## Conclusion:-
The Library Management System provides a convenient and efficient way to manage books and students in a library. It automates various tasks, such as book management, student management, book issuance, and returns. With future enhancements and improvements, the system can become even more robust and user-friendly, further streamlining library operations and enhancing the overall experience for both librarians and students.
