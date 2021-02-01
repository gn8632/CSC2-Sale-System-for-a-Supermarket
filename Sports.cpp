#include"Sports.h"
Sports::Sports(string Name, string Catagory, int Quantity, double price, double siz)
	:Supermarket(Name, Catagory,Quantity, price),size(siz){}

void Sports::setsize(double x) { size = x; }

double Sports::getsize() const { return size; }

void Sports::print() const {
	cout << getname() << " " <<
		getcategory() << " " <<
		getquantity() << " " <<
		getprice() << " " <<
		getsize() << endl;
}