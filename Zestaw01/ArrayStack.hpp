#ifndef STACK_H
#define STACK_H

#include <stdexcept>

class Stack {
	int* arr;
	int top;
	int capacity;

public:
	Stack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
	void push(int x); // Wstawia element na stos
	int pop(); // Usuwa element ze stosu i zwraca jego wartość
	int size(); // Zwraca liczbę elementów na stosie
	bool empty(); // Sprawdza czy stos jest pusty
	bool full(); // Sprawdza czy stos jest pełny
	int top(); //zwraca wartosc z gory stosu (ostatnie zad)
};

#endif // STACK_H

