#include <conio.h> 
#include <iomanip> 
#include <iostream> 
#include <string> 
#include "Supermarket.h"
#include "Electronics.h"
#include "Sports.h"
#include "Food.h"
#include "exception.h"
using namespace std;

void loadItems(vector<Supermarket*> &store);
void Return(vector<Supermarket*> &store);
void Add(vector<Supermarket*> &store);
void Sell(vector<Supermarket*> &store);
void Update(vector<Supermarket*> &store);
void Search(vector<Supermarket*> &store);
void PrintCatalog(vector<Supermarket*> &store);
void Options();

// this is the operations of the store
int main() {
	
	vector<Supermarket*> store;
	loadItems(store);
	Options();
	try 
	{
		int option;
		cout << "Enter an option :";
		cin >> option;

		while (option != 7) {

			if (option == 1) {
				Search(store);

			}
			else if (option == 2)
			{
				Sell(store);
			}
			else if (option == 3)
			{
				Return(store);
			}
			else if (option == 4)
			{
				Add(store);
			}
			else if (option == 5)
			{
				Update(store);
			}
			else if (option == 6)
			{
				PrintCatalog(store);
			}

			Options();
			cout << "Enter An option :";
			cin >> option;
		}
	}
	catch (exception ex) {
		cout << "Error! The program is exiting. Bye Bye :" << ex.what()<<endl;
		cout << "Try again later!\n";
	}
	_getch();
}

void loadItems(vector<Supermarket*> &store) {

	store.push_back(new Electronics("headhones", "Electronics", 10, 3.50, 1.234));
	store.push_back(new Electronics("PC", "Electronics", 10, 300, 7.234));
	store.push_back(new Electronics("DVD", "Electronics", 20, 40.0, 2.234));
	store.push_back(new Electronics("Phone", "Electronics", 10, 245, 1.234));
	store.push_back(new Electronics("Cable", "Electronics", 10, 3.70, 1.234));


	store.push_back(new Sports("base ball", "Sport", 10, 9.99, 2.3));
	store.push_back(new Sports("cricket ball", "Sport", 12, 5.2, 1.3));
	store.push_back(new Sports("soccer ball", "Sport", 7, 50.0, 3.3));
	store.push_back(new Sports("soft ball", "Sport", 10, 5.0, 0.53));
	store.push_back(new Sports("ping pong ball", "Sport", 10, 2.7, 0.73));


	store.push_back(new FOOD("Egg", "Food", 100, 2.99, "USA"));
	store.push_back(new FOOD("Sushi", "Food", 50, 10.99, "Japan"));
	store.push_back(new FOOD("Fish", "Food", 70, 50.99, "Bangladesh"));
	store.push_back(new FOOD("Milk", "Food", 600, 3.99, "USA"));
	store.push_back(new FOOD("Vadoka", "Food", 1000, 12.99, "Russia"));

}

void PrintCatalog(vector<Supermarket*> &store) {
	cout << "************* STORE INVENTORY ****************" << endl;
	for (auto it = store.begin(); it != store.end(); it++) {
		(*it)->print();
	}
	cout << endl;
}

void Options() {

	cout << "1 : Search inventory.\n";
	cout << "2 : Sell items.\n";
	cout << "3 : Return the item.\n";
	cout << "4 : Add new items.\n";
	cout << "5 : Update existing items.\n";
	cout << "6 : Print the catalog\n";
	cout << "7 : Exit.\n";
}
void Search(vector<Supermarket*> &store) 
{
	string search;
	bool sometingPrinted = false;
	cout << "Enter the name you want to search for: ";
	cin >> search;
	vector<Supermarket*>::iterator it;
	for (it = store.begin(); it != store.end(); it++) {

		if ( (*it)->getname() == search || (*it)->getname() == search) {
			(*it)->print();
			sometingPrinted = true;
		}
	}

	if (!sometingPrinted)
		cout << "nothing found in search results" << endl;
}

void Sell(vector<Supermarket*> &store)
{
	int sell;
	string name;

	cout << "Enter the name of what you want to sell: ";
	cin >> name;
	
	vector<Supermarket*>::iterator it;
	for (it = store.begin(); it != store.end(); it++) {

		if ((*it)->getname() == name ) {

			cout << "Enter how many you want to sell: ";
			cin >> sell;

			if ((*it)->getquantity() - sell >= 0)
				(*it)->setquantity((*it)->getquantity() - sell);
			else
				"All items sold out!\n";
			return;
		}
	}
}

void Return(vector<Supermarket*> &store)
{
	int Return_item;
	string name;

	cout << "Enter the name of what you want to return: ";
	cin >> name;

	vector<Supermarket*>::iterator it;
	for (it = store.begin(); it != store.end(); it++) {

		if ((*it)->getname() == name) {

			cout << "Enter how many you want to return: ";
			cin >> Return_item;

			(*it)->setquantity((*it)->getquantity() + Return_item);

			return;
		}
	}
}

void Add(vector<Supermarket*> &store)
{
	string name;
	bool AddItem = false;
	cout << "Enter the name of what you want to add: ";
	cin >> name;

	vector<Supermarket*>::iterator it;
	for (it = store.begin(); it != store.end(); it++) {

		if ((*it)->getname() == name) {

			cout << "The item already exist.\n";
			AddItem = true;
			return;
		}
		
	}
	if (!AddItem)
	{
		string catagory;
		do 
		{
			cout << "Enter the catagory ( Sport, Food, Electronics): ";
			cin >> catagory;

		} while (catagory != "Sport" && catagory != "Food" && catagory != "Electronics");

		
		int quantity;
		double price;

		cout << "Enter the updated name: ";
		cin >> name;

		cout << "Enter the new quantity: ";
		cin >> quantity;

		cout << "Enter the price :";
		cin >> price;

		if (catagory == "Sport")
		{
			double size;
			cout << "Enter the weight of item :";
			cin >> size;
			store.push_back(new Sports(name, catagory, quantity, price, size));
		}

		else if (catagory == "Electronics")
		{
			double size;
			cout << "Enter the weight of item :";
			cin >> size;
			store.push_back(new Electronics(name, catagory, quantity, price, size));
		}

		else if (catagory == "Food")
		{
			string country;
			cout << "What country this item is made: ";
			cin >> country; 
			//getline(cin, country);
			store.push_back(new FOOD(name, catagory, quantity, price, country));
		}


	}

}

void Update(vector<Supermarket*> &store)
{

	bool found = false;
	double Price;
	int quantity;
	string category;
	double weight;
	string country;
	string name;

	cout << "Enter the name of what you want to add: ";
	cin >> name;

	vector<Supermarket*>::iterator it;
	for (it = store.begin(); it != store.end(); it++) {

		if ((*it)->getname() == name) {

			cout << "The item already exist.\n";
			found = true;
			return;
		}

	}

	if (found == true)
	{

		cout << "please enter a price";
		cin >> Price;
		cout << "please enter a quantity";
		cin >> quantity;
		cout << "please enter a categories";
		cin >> category;

		if (category == "Food")
		{
			string country;
			cout << "please enter the country name:";
			getline(cin, country);
			
			delete (*it);
			store.push_back(new FOOD(name, category, quantity, Price, country));
			return;
		}

		if (category == "Sport")
		{
			double size;
			cout << "please enter a size";
			cin >> size;

			delete (*it);
			store.push_back(new Sports(name, category, quantity, Price, size));
			return;
		}


		if (category == "Electronics")
		{
			double size;
			cout << "please enter a grounded and not grounded";
			cin >> size;

			delete (*it);
			store.push_back(new Electronics(name, category, quantity, Price, size));
			return;
		}

		cout << "category invalid.";
	}
}