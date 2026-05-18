#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using std::cout;
using std::endl;

namespace myStack {
	template <typename T>
	class Node {
	public:
		T info;
		Node* next;
		Node* prev;

		Node(T value) { info = value; next = prev = nullptr; }
	};


	template <typename U>
	class Stack {  // LIFO = Last In - First Out
		Node<U>* head;
		Node<U>* current;
	public:
		Stack() { 
			head = current = nullptr;
		}
		~Stack() {
			while (!isEmpty()) {
				pop_back();
			}
		}

		bool isEmpty()const { 
			return head == nullptr || current == nullptr;
		}
		U top()const { 
			if (isEmpty()) throw std::runtime_error("List is empty");

			return current->info;
		}
		void push_back(U value) { 
			Node<U>* item = new Node<U>(value);

			if (isEmpty()) {
				head = current = item;
			}
			else {
				current->next = item;
				item->prev = current;
				current = item;
			}
		}
		void pop_back() { 
			if (!isEmpty()) {

				if (head != current) { // багато вузлів
					current = current->prev;
					delete current->next;
					current->next = nullptr;
				}
				else { // head = current
					delete head;
					head = current = nullptr;

				}
			}
		}
		void showStack()const { 
			if (isEmpty()) {
				cout << "Stack is Empty\n" << endl;
			}
			else {
				Node<U>* p = head;
				while (p != nullptr) {
					cout << " " << p->info;
					p = p->next;
				}
				cout << endl;
			}
		}
	};
}
