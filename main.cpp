#include <algorithm>
#include <iostream>
#include "functionO.h"

void test(function& fun) {
	fun();
}

int main() {
	Function(hi,
		std::cout << "cool\n";
		std::cout << "fun is over\n";
	)
	test(hi);
}



