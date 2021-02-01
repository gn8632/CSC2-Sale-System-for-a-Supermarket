#include <iostream>
#include <fstream>
#include <vector>
#include "Supermarket.h"
#include "Electronics.h"


using namespace std;







void loadCat(vector<Supermarket*> &cat);
void searchInventory(vector<Supermarket*> &cat);
void sellItems(vector<Supermarket*> &cat);
void returnItems(vector<Supermarket*> &cat);
void addNewItems(vector<Supermarket*> &cat);
void updateItems(vector<Supermarket*> &cat);
void saveAndExit(vector<Supermarket*> &cat);

int main()
{
	vector <Supermarket*> cat;
	loadCat(cat);










	saveAndExit(cat);
	return 0;
}

void loadCat(vector<Supermarket*>& cat)
{
	ifstream inFile;

	string TEXT_FILE = "electronics.txt";
	inFile.open(TEXT_FILE);

	if (!inFile.is_open())
	{
		cout << "could not open the file.\n";
	}
	else
	{
		string name;
		string category;
		int quantity;
		double cost;
		double size;

		while (inFile.peek() != EOF)
		{
			inFile >> name >> category >> quantity >> cost >> size;
			cat.push_back(new Electronics("headphone", "Electronics", 10, 20.00, 50.0));
		}
	}
	inFile.close();
}

void saveAndExit(vector<Supermarket*>& cat)
{
	vector<Supermarket*>::iterator it;

	for (it = cat.begin(); it != cat.end(); it++)
		delete (*it);
}
