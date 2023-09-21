#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


struct node 
{
    float priority;
    string data;
    struct node* next;
};

template<class T, class T2>
class Priority_Queue
{
private:
    node* head;

public:
    
    Priority_Queue()
    {
        head = NULL;
    }

    //func to insert elements with the priority
    void insert(T i, T2 p)
    {
        node* temp, * q;
        temp = new node;
        temp->data = i;
        temp->priority = p;

        //checks if queue is empty of if the priority is the highest and inserts
        if (head == NULL || p < head->priority)
        {
            temp->next = head;
            head = temp;
        }
        //iterates through the list until it finds a lower priority
        else
        {
            q = head;
            while (q->next != NULL && q->next->priority <= p)
                q = q->next;
            temp->next = q->next;
            q->next = temp;
        }
    }
    //Function to check if queue is empty
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    //func to pop the top element
    void pop(node** head)
    {
        node* temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }

    //func to remove an elemet
    void remove()
    {
        node* temp;
        if (head == NULL)
            cout << "Queue Underflow\n";
        else
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    //void remove(T t, Priority_Queue<T, T2>& PQ, Priority_Queue<T, T2> q)
    //{
    //    //Priority_Queue<T, T2> q;
    //    node* temp;
    //    temp = new node;
    //    temp->data = t;
    //    while (temp->data != head->data)
    //    {
    //        q.insert(head->data, head->priority);
    //        head = head->next;
    //    }
    //    if (temp->data == head->data)
    //    {
    //        temp = head;
    //        head = head->next;
    //        free(temp);

    //        while (head -> next != NULL)
    //        {
    //            q.insert(head->data, head->priority);
    //            head = head->next;
    //        }
    //        if (head->next == NULL)
    //        {
    //            q.insert(head->data, head->priority);
    //            head = NULL;
    //        }
    //    }
    //    //q.print();

    //}


    //func to print the queue with its priority
    void print() 
    {
        node* ptr;
        ptr = head;
        //check if empty
        if (head == NULL)
            cout << "\nNo items have been added\n";
        //prints the item and its priority
        else
        {
            cout << "\nQueue is:\n";
            cout << "Priority  |  Item\n";
            while (ptr != NULL)
            {
                cout << ptr->priority << "   |   " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};