#include "Electronics.h"
#include<string>
using namespace std;


//Electronics::Electronics() {
//	size = 0;
//}

Electronics::Electronics(string name, string category, int quantity, double price, double size)
	:Supermarket(name, category, quantity, price)
{
	this->size = size;
}

void Electronics::setsize(double SIZE)
{
	size = SIZE;
}

double Electronics::getsize() const
{
	return size;
}

void Electronics::print() const
{
	cout << getname() << " " <<
		getcategory() << " " <<
		getquantity() << " " <<
		getprice() << " " <<
		getsize() << endl;
}

