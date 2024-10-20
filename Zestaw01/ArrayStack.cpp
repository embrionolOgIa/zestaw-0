#include "ArrayStack.hpp"
#include <iostream>

Stack::Stack(int capacity) {

	this->capacity = capacity;
	arr = new int[capacity];
	top = -1;
}

// wstawia element na stos
void Stack::push(int x) {

	if (full()) {
		throw std::out_of_range("Stos pelny");
	}
	arr[++top] = x;
}

// usuwa element ze stosu i zwraca jego wartosc
int Stack::pop() {

	if (empty()) {
		throw std::out_of_range("Stos pusty");
	}
	return arr[top-1];
}

// zwraca liczbę elementów na stosie
int Stack::size() {
	return top + 1;
}

// sprawdza czy stos jest pusty
bool Stack::empty() {

	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}

// sprawdza czy stos jest pelny
bool Stack::full() {

    if (top == capacity - 1) {
        return true;
    }
    else {
        return false;
    }
}

