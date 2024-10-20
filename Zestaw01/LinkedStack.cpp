#include <iostream>
#include "LinkedStack.hpp"
#include "Node.hpp"

LinkedStack::LinkedStack() {

	this->head = nullptr;
}

void LinkedStack::linkedPush(int x) {

	Node* new_node = new Node(x);

	if (!new_node) {
		throw std::out_of_range("Stos pelny");
	}
	else {
		// dolacz nowy node to obecnie ostatniego
		new_node->next = head;

		// nowy node jest teraz ostatni
		head = new_node;

		size++;
	}   
}

int LinkedStack::linkedPop() {
	if (this->linkedEmpty()) {
		throw std::out_of_range("Stos pusty");
	}
	else {
		Node* temp = head;
		int popped_value = temp->data; // zapisz wartosc do zwrocenia
		head = head->next;
		delete temp;
		size--;
		return popped_value;
	}
}

int LinkedStack::linkedSize() {
	return size;
}

bool LinkedStack::linkedEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int LinkedStack::top() {

	if (linkedEmpty()) {
		throw std::out_of_range("Stos pusty");
	}
	return head->data;
}


