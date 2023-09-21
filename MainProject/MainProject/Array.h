#pragma once
#include<iostream>
using namespace std;

template<class T>
class Array
{
public:
	T* arr;
	int arraySize;
	int count = 0;

	Array(int size)
	{
		arr = new T[size];
		arraySize = size;
	}
	//func to iterate through array and print
	void printArray()
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << ", ";
		}
	}
	//Function to count the number of a specific item
	void CountElements(T element)
	{
		int amt = 0;

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == element)
				amt++;
		}
		cout << "There are " << amt << " items with that name! \n\n";
	}

	//func to insert at start of the array
	void Insert(T element)
	{
		arr[count] = element;
		count++;
	}

	//function to delete a specific element from the array
	void Delete(T element)
	{
		//iterates until item is found
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == element)
			{
				//shifts all other elements left
				for (int j = i; j < count - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
				count--;
				break;
			}
		}
	}
};