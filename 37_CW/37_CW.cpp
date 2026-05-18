// 37_CW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyStack.h"
#include <string>

bool isValidBrackets(std::string line){
	myStack::Stack<char> brackets;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '(' || line[i] == '{' || line[i] == '[') {
			brackets.push_back(line[i]);
		}
		else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
			if (brackets.isEmpty()) {
				return false;
			}
			else {
				char last = brackets.top();
				if (last == '(' && line[i] == ')' || last == '{' && line[i] == '}' 
					|| last == '[' && line[i] == ']') {
					brackets.pop_back();
				}
				else {
					return false;
				}
			}
		}
	}
	if (brackets.isEmpty())
		return true;
	else {
		return false;
	}
}

int main()
{

	/*

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
	*/


	cout << "[()]{}" << isValidBrackets("[()] {}") << endl ;

	cout << "][" << isValidBrackets("][") << endl;
	cout << "[({)]}" << isValidBrackets("[({)]}") << endl;

	return 0;
}
