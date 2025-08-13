#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool isIssued;
    Book *left;
    Book *right;
};

class Student
{
public:
    int id;
    string name;
    Student *next;
};

class Library
{
private:
    Book *root;
    Student *head;

public:
    Library()
    {
        root = NULL;
        head = NULL;
    }

    // Function to add a book using BST
    void addBook(int id, string title, string author)
    {
        Book *newBook = new Book;
        newBook->id = id;
        newBook->title = title;
        newBook->author = author;
        newBook->isIssued = false;
        newBook->left = NULL;
        newBook->right = NULL;

        if (root == NULL)
        {
            root = newBook;
        }
        else
        {
            Book *current = root;
            Book *parent;
            while (true)
            {
                parent = current;
                if (id < current->id)
                {
                    current = current->left;
                    if (current == NULL)
                    {
                        parent->left = newBook;
                        break;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == NULL)
                    {
                        parent->right = newBook;
                        break;
                    }
                }
            }
        }
    }

    // to get 1st element of root data
    Book *getRoot()  //to get 1st element of root data
    {
        return root;
    }

    // Function to delete a book
    void deleteBook(int id)
    {
        root = deleteBookHelper(root, id);
    }

    // Recursive helper function to delete a book
    Book *deleteBookHelper(Book *current, int id)
    {
        if (current == NULL)
        {
            cout << "Book not found!" << endl;
            return current;
        }

        if (id < current->id)
        {
            current->left = deleteBookHelper(current->left, id);
        }
        else if (id > current->id)
        {
            current->right = deleteBookHelper(current->right, id);
        }
        else
        {
            if (current->left == NULL && current->right == NULL)
            {
                delete current;
                current = NULL;
            }
            else if (current->left == NULL)
            {
                Book *temp = current;
                current = current->right;
                delete temp;
            }
            else if (current->right == NULL)
            {
                Book *temp = current;
                current = current->left;
                delete temp;
            }
            else
            {
                Book *temp = findMin(current->right);
                current->id = temp->id;
                current->title = temp->title;
                current->author = temp->author;
                current->right = deleteBookHelper(current->right, temp->id);
            }
            cout << "\t\t\t____________________________________________________________" << endl;
            cout << "\t\t\t  Book with ID " << id << " has been deleted Sucessfully...." << endl;
            cout << "\t\t\t____________________________________________________________" << endl;
        }
        return current;
    }

    // Function to find the minimum book in a BST
    Book *findMin(Book *node)
    {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // Function to search a book using BST
    Book *searchBook(int id)
    {
        return searchBookHelper(root, id);
    }

    // Recursive helper function to search a book using BST
    Book *searchBookHelper(Book *current, int id)
    {
        if (current == NULL || current->id == id)
            return current;

        if (id < current->id)
            return searchBookHelper(current->left, id);

        return searchBookHelper(current->right, id);
    }

    // Function to sort books using an array
    void sortBooks()
    {
        int size = countBooks(root);
        int *arr = new int[size];
        int index = 0;
        inorderTraversal(root, arr, index);
        quickSort(arr, 0, size - 1);
        cout << "ID\t\tTitle\t\tAuthor" << endl;
        for (int i = 0; i < size; i++)
        {
            Book *book = searchBook(arr[i]);
            cout << book->id;
            cout << "\t\t" << book->title;
            cout << "\t\t" << book->author << endl;
        }
        delete[] arr;
    }

    // Function to count the number of books in a BST
    int countBooks(Book *node)
    {
        if (node == NULL)
            return 0;

        return countBooks(node->left) + countBooks(node->right) + 1;
    }

    // Inorder traversal of a BST and store book IDs in an array
    void inorderTraversal(Book *node, int *arr, int &index)
    {
        if (node == NULL)
            return;

        inorderTraversal(node->left, arr, index);
        arr[index++] = node->id;
        inorderTraversal(node->right, arr, index);
    }

    // Function to display books in ascending order of their IDs (inorder traversal)
    void displayBooksInorder(Book *current)
    {
        if (current == NULL)
            return;

        displayBooksInorder(current->left);
        cout << "ID: " << current->id << ", Title: " << current->title << ", Author: " << current->author;
        if (current->isIssued)
        {
            cout << " (Issued)" << endl;
        }
        else
        {
            cout << " (Available)" << endl;
        }
        displayBooksInorder(current->right);
    }

    void displayBooksPreOrder(Book *node)
    {

        if (node != NULL)
        {

            cout << node->id;
            cout << "\t\t\t" << node->title;
            cout << "\t\t\t" << node->author;

            if (node->isIssued)
            {
                cout << " \t\t(Issued)" << endl;
            }
            else
            {
                cout << "\t\t(Available)" << endl;
            }
            displayBooksPreOrder(node->left);
            displayBooksPreOrder(node->right);
        }
    }

    // Quicksort algorithm to sort the book IDs array
    void quickSort(int *arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    // Partition function for quicksort
    int partition(int *arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Function to register a student
    void registerStudent(int id, string name)
    {
        Student *newStudent = new Student;
        newStudent->id = id;
        newStudent->name = name;
        newStudent->next = NULL;

        if (head == NULL)
        {
            head = newStudent;
        }
        else
        {
            Student *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    // Function to check if a student is registered
    bool isStudentRegistered(int id)
    {
        Student *current = head;
        while (current != NULL)
        {
            if (current->id == id)
                return true;
            current = current->next;
        }
        return false;
    }

    // Function to issue a book to a registered student
    void issueBook(int studentId, int bookId)
    {
        if (isStudentRegistered(studentId))
        {
            Book *book = searchBook(bookId);
            if (book != NULL)
            {
                if (!book->isIssued)
                {
                    book->isIssued = true;
                    cout << "\t\t\t_____________________________________________________________" << endl;
                    cout << "\t\t\t   Book with ID " << bookId << " Sucessfully issued to Roll Number " << studentId << endl;
                    cout << "\t\t\t______________________________________________________________" << endl;
                }
                else
                {
                    cout << "\t\t\t____________________________________" << endl;
                    cout << "\t\t\t   Book is already issued!" << endl;
                    cout << "\t\t\t____________________________________" << endl;
                }
            }
            else
            {
                cout << "Book not found!" << endl;
            }
        }
        else
        {
            cout << "\t\t\t__________________________________" << endl;
            cout << "\t\t\t  Student is not registered!" << endl;
            cout << "\t\t\t__________________________________" << endl;
        }
    }

    // Function to return a book
    void returnBook(int bookId)
    {
        Book *book = searchBook(bookId);
        if (book != NULL)
        {
            if (book->isIssued)
            {
                book->isIssued = false;
                cout << "\t\t\t_____________________________________________________" << endl;
                cout << "\t\t\t   Book with ID " << bookId << " has been Sucessfully returned..." << endl;
                cout << "\t\t\t_____________________________________________________" << endl;
            }
            else
            {
                cout << "Book is not issued!" << endl;
            }
        }
        else
        {
            cout << "Book not found!" << endl;
        }
    }

    // Function to display all books
    void displayBooks(Book *node)
    {
        if (node != NULL)
        {
            displayBooks(node->left);
            cout << "ID: " << node->id << " | Title: " << node->title << " | Author: " << node->author;
            if (node->isIssued)
            {
                cout << " (Issued)";
            }
            cout << endl;
            displayBooks(node->right);
        }
    }

    // Function to display all registered students
    void displayStudents()
    {
        if (head == NULL)
        {
            cout << "No students in the list..." << endl;
        }
        else
        {
            Student *current = head;
            cout << "\t\t\t_______________________________" << endl;
            cout << "\t\t\t\tList of Students:" << endl;
            cout << "\t\t\t_______________________________" << endl;
            cout << "Roll Number\t\t\tName" << endl;
            while (current != NULL)
            {
                cout << current->id;
                cout << "\t\t\t\t" << current->name << endl;
                current = current->next;
            }
        }
    }
};

// Function to display the menu and get user's choice
int displayMenu()
{
    int choice;
    cout << "\n\t\t\t ___________________________________";
    cout << "\n\t\t\t|                                   |";
    cout << "\n\t\t\t|          LIBRARY MANAGEMENT       |";
    cout << "\n\t\t\t|___________________________________|\n";
    cout << "\t\t\t|                                   |" << endl;
    cout << "\t\t\t| 1. Add a new Book                 |" << endl;
    cout << "\t\t\t| 2. Delete a Book                  |" << endl;
    cout << "\t\t\t| 3. Search a Book                  |" << endl;
    cout << "\t\t\t| 4. Sort Books By ID               |" << endl;
    cout << "\t\t\t| 5. Register a Student             |" << endl;
    cout << "\t\t\t| 6. Issue Book                     |" << endl;
    cout << "\t\t\t| 7. Return Book                    |" << endl;
    cout << "\t\t\t| 8. Show All Books                 |" << endl;
    cout << "\t\t\t| 9. Show All Registered Students   |" << endl;
    cout << "\t\t\t| 10. Exit                          |" << endl;
    cout << "\t\t\t|___________________________________|" << endl;
    cout << "\n\t\t\tEnter your choice (1-10): ";
    cin >> choice;
    return choice;
}

int main()
{
    cout << "\t\t\t\t__________________________________________________" << endl;
    cout << "\t\t\t\t *** Welcome to the Library Management System***" << endl;
    cout << "\t\t\t\t__________________________________________________" << endl;

    Library library;
    int choice;

    while (true)
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
        {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            cout << "\t\t\t___________________________________________" << endl;
            cout << "\t\t\t\tBook Added Successfully..." << endl;
            cout << "\t\t\t___________________________________________" << endl;
            sleep(3);
            system("cls");
            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 2:
        {
            cout << "ID\t\t\tTitle\t\t\tAuthor " << endl;
            library.displayBooksPreOrder(library.getRoot());

            int id;
            cout << "Enter Book ID of the book to Delete: ";
            cin >> id;
            library.deleteBook(id);

            sleep(3);
            system("cls");
            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 3:
        {
            system("cls");
            int id;
            cout << "Enter Book ID to Search: ";
            cin >> id;
            Book *book = library.searchBook(id);
            if (book != NULL)
            {
                cout << "____________________________" << endl;
                cout << " ***Book Found***" << endl;
                cout << "____________________________" << endl;

                cout << "ID    : " << book->id << endl;
                cout << "Title : " << book->title << endl;
                cout << "Author: " << book->author << endl;
            }
            else
            {
                cout << "________________________________" << endl;
                cout << "--> Book with ID " << id << " not Found." << endl;
                cout << "________________________________" << endl;
            }
            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\t\t\t_________________________________" << endl;
            cout << "\t\t\t  Books sorted successfully..." << endl;
            cout << "\t\t\t__________________________________" << endl;
            library.sortBooks();

            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 5:
        {
            int id;
            string name;
            cout << "Enter Student's Roll Number : ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            library.registerStudent(id, name);

            cout << "\t\t\t____________________________________________________________________" << endl;
            cout << "\t\t\t  Student with Roll No. " << id << " registered Sucessfully..." << endl;
            cout << "\t\t\t_____________________________________________________________________" << endl;

            sleep(3);
            system("cls");
            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 6:
        {
            int studentId, bookId;
            cout << "Enter Student Roll Number: ";
            cin >> studentId;
            cout << "Enter Book ID: ";
            cin >> bookId;
            library.issueBook(studentId, bookId);

            sleep(3);
            system("cls");
            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 7:
        {
            int bookId;
            cout << "Enter Book ID to Return: ";
            cin >> bookId;
            library.returnBook(bookId);

            sleep(3);
            system("cls");
            cout << "\t\t\t\t______________________________________________" << endl;
            cout << "\t\t\t\t  Welcome to the Library Management System" << endl;
            cout << "\t\t\t\t______________________________________________" << endl;
            break;
        }
        case 8:
        {
            system("cls");
            cout << "\t\t\t___________________________________" << endl;
            cout << "\t\t\t\tBooks in the library:" << endl;
            cout << "\t\t\t___________________________________" << endl;
            cout << "ID\t\t\tTitle\t\t\tAuthor " << endl;
            library.displayBooksPreOrder(library.getRoot());
            if (library.getRoot() == NULL)
            {
                cout << "No Books in the Library...";
            }
            break;
        }

        case 9:
        {
            system("cls");
            library.displayStudents();
            break;
        }

        case 10:
            cout << "\t\t\t______________________________________" << endl;
            cout << "\t\t\t   Exiting the program. Goodbye!" << endl;
            cout << "\t\t\t______________________________________" << endl;
            exit(0);
            
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}
