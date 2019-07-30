#include <algorithm>
#include <iostream>
#include "Oct.h"
#include "functionO.h"
#include <stdio.h>


class MyClass
{
public:
	void* doSomthing(Func::FUNCTION &function) {
		//return function(0);
	}
	void* doSomthingWithArguments(Func::FUNCTION &function) {
		return function(new Func::LinkList(4));
	}
};



int main() {
	MyClass myclass;

	Func_Function(myfunction)
		int i;
		std::cout << "Please enter an integer value: ";
		std::cin >> i;
		std::cout << "The value you entered is " << i;
		std::cout << " and its multiplied by passed argument is " << i * Func_arg(0,int) << ".\n";
	Func_end(myfunction);

	myclass.doSomthingWithArguments(myfunction);
}


