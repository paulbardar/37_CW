// 37_CW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyStack.h"


int main()
{

	myStack::Stack<int> nums;
	nums.showStack(); // empty

	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(6);

	nums.showStack();
	cout << "===========================================\n" << endl;

	// Розвантаження = обробка стеку

	while (!nums.isEmpty()) {
		cout << "TOP" << nums.top() << endl;
		nums.showStack();
		cout << endl;

		nums.pop_back();
	}

	cout << "===========================\n" << endl;

	nums.showStack();


	return 0;
}
