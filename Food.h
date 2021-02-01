#ifndef FOOD_H
#define FOOD_H
#include "Supermarket.h"
class FOOD :public Supermarket {
public:
	FOOD(string, string, int, double, string);
	void setMade(string);
	string getMade() const;
	void print() const;


private:
	string made;
};

#endif // !FOOD_H

