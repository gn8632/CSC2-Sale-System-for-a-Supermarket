#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include <iostream>
#include <string>
#include "Supermarket.h"
//using namespace std;

class Electronics : public Supermarket
{
public:
	Electronics(string, string, int, double, double);
	void setsize(double);
	double getsize() const;
	//Electronics();
	void print() const;


private:
	double size;
	
};

#endif // !ELECTRONICS_H
