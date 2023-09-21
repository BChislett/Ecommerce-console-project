#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* current;

    Node()
    {
        data = "";
        next = NULL;
        current = NULL;
    }

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template<class T, class T2>
class Linkedlist {
    Node* head;
    Node* current;

public:
    // Default constructor
    Linkedlist() { head = NULL; }

    //Function to insert a new item
    void insertNode(T data)
    {
        // Create the new Node.
        Node* newNode = new Node(data);

        // Assign to head
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Traverse till end of list
        Node* temp = head;
        while (temp->next != NULL) {

            temp = temp->next;
        }

        // Insert at the last.
        temp->next = newNode;
    }
    //Function to print the list
    void printList()
    {
        Node* temp = head;

        // Check for empty list.
        if (head == NULL) {
            cout << "There are no items in this category" << endl;
            return;
        }

        // Traverse the list.
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    //Function to delete a specific node
    void deleteNode(T2 nodeOffset)
    {
        Node* temp1 = head, * temp2 = NULL;
        int ListLen = 0;

        if (head == NULL) {
            cout << "There are no items in this category" << endl;
            return;
        }

        // Find length of the linked-list.
        while (temp1 != NULL) {
            temp1 = temp1->next;
            ListLen++;
        }
        
        //checks if node to delete is within the length of list 
        if (ListLen < nodeOffset) {
            cout << "Index out of range"
                << endl;
            return;
        }

        // Declare temp1
        temp1 = head;

        // Deleting the head.
        if (nodeOffset == 1) {

            head = head->next;
            delete temp1;
            return;
        }

        // Traverse the list to find the node to delete.
        while (nodeOffset-- > 1) {

            temp2 = temp1;

            temp1 = temp1->next;
        }


        temp2->next = temp1->next;

        delete temp1;
    }

    //Function to find the correct node then call the delet function at that node
    void find_data(T item)
    {
        int pos = 0;

        //check if empty
        if (head == NULL)
        {
            return;
        }

        current = head;
        //loop until data value is found then call delete to remove it
        while (current->next != NULL)
        {
            if (current->data == item)
            {
                deleteNode(pos + 1);

                return;
            }

            current = current->next;
            pos++;
        }
        if (current->next == NULL)
        {
            if (current->data == item)
            {
                deleteNode(pos+1);

                return;
            }
        }
    }
};