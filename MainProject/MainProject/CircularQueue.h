#pragma once

#include<bits/stdc++.h>
using namespace std;


//Purchase History Class
template <class T>
class Queue
{
    // Initialize front and rear
    int rear, front;
    int size;
    T* arr;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new T[s];
    }

    void enQueue(T value);
    T deQueue();
    void displayQueue();
};


// Function to add elements into the circular queue 
template <class T>
void Queue<T>::enQueue(T value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        deQueue();
        return;
    }

    //Check if the queue is empty and inerts first element if it is
    else if (front == -1) 
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
template <class T>
T Queue<T>::deQueue()
{
    //check if empty
    if (front == -1)
    {
        std::cout << "\nNo customers have been added";
    }

    T data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

// Function to print the values in the circular queue
template <class T>
void Queue<T>::displayQueue()
{
    //check if empty
    if (front == -1)
    {
        std::cout << "\nNo previous customers";
        return;
    }
    std::cout << "\nCustomer History: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            std::cout << "\n" << arr[i];
    }
    else
    {
        for (int i = front; i < size; i++)
            std::cout << "\n" << arr[i];

        for (int i = 0; i <= rear; i++)
            std::cout << "\n" << arr[i];
    }
}

