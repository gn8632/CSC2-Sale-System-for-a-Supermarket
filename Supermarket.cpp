#include "Supermarket.h"

Supermarket::Supermarket(string N, string Ca, int Qan, double P)
	:name(N),category(Ca), quantity(Qan), price(P) {}

bool Supermarket::Search(string searchValue)
{
	return (searchValue == getname() || searchValue == getcategory());
}

void Supermarket::setname(string N)
{
	name = N;
}

void Supermarket::setcategory(string cata) { category = cata; }

string Supermarket::getcategory() const { return category; }

void Supermarket::setquantity(int Q)
{
	quantity = Q;
}

void Supermarket::setprice(double P)
{
	price = P;
}

string Supermarket::getname() const
{
	return name;
}


int Supermarket::getquantity() const
{
	return quantity;
}

double Supermarket::getprice() const
{
	return price;
}
