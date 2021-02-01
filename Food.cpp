#include "Food.h"
FOOD::FOOD(string name, string catagory, int quantity, double price, string country)
	:Supermarket(name,catagory,quantity,price),made(country){}


void FOOD::setMade(string name) { made = name; }

string FOOD::getMade() const { return made; }

void FOOD::print() const {
	cout << getname() << " " <<
		getcategory() << " " <<
		getquantity() << " " <<
		getprice() << " " <<
		getMade() << endl;
}