#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <conio.h> 
#include <cstdlib> 
#include <fstream> 
#include <iomanip> 
#include <iostream> 
#include <string> 
#include<vector>

using namespace std;

class Supermarket {
public:
	Supermarket(string, string, int, double);
	Supermarket() {};

	virtual void print() const =0; 
	bool Search(string);
	
	virtual ~Supermarket() {}

	void setname(string);
	void setcategory(string);
	void setquantity(int);
	void setprice(double);
	string getname() const;
	string getcategory() const;
	int getquantity() const;
	double getprice() const;

private:
	
	string name;
	string category;
	int quantity;
	double price;
};



#endif // SUPERMARKET_H