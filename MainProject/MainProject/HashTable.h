#pragma once
#include <iostream>
#include <list>
using namespace std;

template<class T>
class Hash
{
    int BUCKET;    // No. of buckets

    // Pointer to an array containing buckets
    list<int>* table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(T x);

    // deletes a key from hash table
    void deleteItem(T key);

    // hash function to map values to key
    int hashFunction(T x) {
        return (x % BUCKET);
    }

    void displayHash();
};
template<class T>
Hash<T>::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

template<class T>
void Hash<T>::insertItem(T key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

template<class T>
void Hash<T>::deleteItem(T key)
{
	// get the hash index of key
	int index = hashFunction(key);

	// find the key in (index)th list
	list <int> ::iterator i;
	for (i = table[index].begin();
		i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it
	if (i != table[index].end())
		table[index].erase(i);
}

// function to display hash table
template<class T>

void Hash<T>::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}