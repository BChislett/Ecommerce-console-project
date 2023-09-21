#include<iostream>
#include<string>
#include"Array.h"
#include"HashTable.h"
#include"PriorityQueue.h"
#include"CircularQueue.h"
#include"LinkedList.h"
#include<string.h>
using namespace std;



int main()
{
	//Number of elemnts that will be added to the list
	int dataAmt;

	std::cout << "How many items will you be adding? \n";
	std::cin >> dataAmt;

	Priority_Queue<string, double> PricePQ; //priority queue which sortes the items by price lowest to highest
	Priority_Queue<string, int> ExpDatePQ; //Priority queue which sortes items by expiration date with the nearest fist 

	//Linked lists for each different category 
	Linkedlist<string, int> Dairy;
	Linkedlist<string, int> FandV;
	Linkedlist<string, int> MandP;
	Linkedlist<string, int> Grains;
	Linkedlist<string, int> Sugars;
	Linkedlist<string, int> Bev;
	Linkedlist<string, int> other;



	//Queue to store the customer history
	Queue<string> CustumerQueue(10);

	//Array to store all items
	Array<string> array(dataAmt);

	int selection = 0;
	int c;

	int queueNum = 1;


	do
	{
		cout << "\n\n==================================================\n";
		cout << "1.Insert an item\n";
		cout << "2.Delete an item\n";
		cout << "3.Count a specific item\n";
		cout << "4.Sort items by expiration date\n";
		cout << "5.Sort items by price\n";
		cout << "6.Display items belonging to a certain category\n";
		cout << "7.Check the customer history\n";
		cout << "8.Exit\n";
		cout << "==================================================\n\n";

		cout << "Enter your choice : ";

		cin >> c;

		switch (c)
		{
			case 1:
			{
				string item;

				cout << "What would you like to add?" << endl;
				//getline(cin, item);
				cin >> item;

				array.Insert(item);

				double price;
				cout << "What is the price? \n";
				cin >> price;
				int date;
				cout << "how long until it expires? \n";
				cin >> date;

				int group;

				cout << "What category does this item belong to? \n";
				cout << "1.Dairy \n";
				cout << "2.Fruit & Vegetables\n";
				cout << "3.Meat and poultry\n";
				cout << "4.Grains\n";
				cout << "5.Added Sugars\n";
				cout << "6.Beverages\n";
				cout << "7.Other\n";
				cin >> group;

				if (group == 1)
					Dairy.insertNode(item);

				if (group == 2)
					FandV.insertNode(item);

				if (group == 3)
					MandP.insertNode(item);

				if (group == 4)
					Grains.insertNode(item);

				if (group == 5)
					Sugars.insertNode(item);

				if (group == 6)
					Bev.insertNode(item);
				if (group == 7)
					other.insertNode(item);

				PricePQ.insert(item, price);
				ExpDatePQ.insert(item, date);

				cout << "\nItems: ";
				array.printArray();
				cout << endl;

				break;

			}

			case 2:
			{
				string item;
				cout << "What would you like to remove?\n";
				cin >> item;
				array.Delete(item);

				Dairy.find_data(item);
				FandV.find_data(item);
				MandP.find_data(item);
				Grains.find_data(item);
				Sugars.find_data(item);
				Bev.find_data(item);
				other.find_data(item);

				PricePQ.remove();
				ExpDatePQ.remove();

				cout << "The new list of items it: ";
				array.printArray();
				

				break;

			}

			case 3:
			{
				string element;
				cout << "What element do you want to count? \n";
				cin >> element;
				array.CountElements(element);
				break;
			}

			case 4:
				cout << "Sorted by expiration date: ";
				ExpDatePQ.print();

				break;
			case 5:
				cout << "Sorted by price: ";
				PricePQ.print();

				break;
			case 6:
			{
				int grp;
				cout << "What category do you want to display? \n";
				cout << "1.Dairy \n";
				cout << "2.Fruit & Vegetables\n";
				cout << "3.Meat and poultry\n";
				cout << "4.Grains\n";
				cout << "5.Added Sugars\n";
				cout << "6.Beverages\n";
				cin >> grp;

				if (grp == 1)
				{
					cout << "\nDairy products: ";
					Dairy.printList();
				}

				if (grp == 2)
				{
					cout << "\nFruits and Vegetables: ";
					FandV.printList();

				}

				if (grp == 3)
				{
					cout << "\nMeat and Poultry: ";
					MandP.printList();
				}

				if (grp == 4)
				{
					cout << "\nGrains: ";
					Grains.printList();
				}

				if (grp == 5)
				{
					cout << "\nAdded Sugars: ";					
					Sugars.printList();
				}

				if (grp == 6)
				{
					cout << "\nBeverages: ";
					Bev.printList();
				}
				if (grp == 7)
				{
					cout << "\nOther: ";
					other.printList();
				}
				break;
			}
			case 7:
			{
				int deci;
				cout << "Would you like to: \n1. Add a new customer \n2. Display list of previous customers\n";
				cin >> deci;

				if (deci == 1)
				{
					string name;
					string first = "";
					string last = "";
					string email = "";
					string phone = "";

					cout << "Enter first Name: ";
					cin >> first;

					cout << "Enter last name: ";
					cin >> last;


					cout << "Enter an email: ";
					cin >> email;

					cout << "Enter a phone number: ";
					cin >> phone;


					name = first + " " + last + " \n Email: " + email + "\n Phone #:" + phone;

					CustumerQueue.enQueue(name);
					deci = 0;
				}
				if (deci == 2)
					CustumerQueue.displayQueue();

				break;
			}

		case 8:
			break;
		default:
			cout << "Invalid choice\n";
		}
	} while (c != 8);

	cout << "\n\nFinal Item List: ";
	array.printArray();

	cout << "\n\nFinal Customer List: ";
	CustumerQueue.displayQueue();

	return 0;
}

