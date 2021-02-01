#ifndef SPORTS_H
#define SPORTS_H
#include "Supermarket.h"

class Sports : public Supermarket {

public:
	Sports(string, string, int, double, double);
	void setsize(double);
	double getsize() const;
	void print() const;


private:
	double size;
};
#endif
