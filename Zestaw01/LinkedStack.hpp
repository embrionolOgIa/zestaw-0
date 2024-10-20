#include <iostream>
#include <stdexcept>
#include "Node.hpp"

class LinkedStack {

	Node* head;

private:
	int size = 0;

public:
	LinkedStack(); // Konstruktor. Argumentem jest rozmiar tablicy.
	void linkedPush(int x); // Wstawia element na stos
	int linkedPop(); // Usuwa element ze stosu i zwraca jego wartość
	int linkedSize(); // Zwraca liczbę elementów na stosie
	bool linkedEmpty(); // Sprawdza czy stos jest pusty
	int top(); //zwraca wartosc z gory stosu (ostatnie zad)

	friend class Node;
};
