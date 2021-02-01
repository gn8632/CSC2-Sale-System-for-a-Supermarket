#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
using namespace std;

class Exception{
private:
	string message;
public:
	//implement the methods
	Exception(string m) :message(m) {}
	string what() {
		return message;
	}
};

#endif // !EXCEPTION_H

