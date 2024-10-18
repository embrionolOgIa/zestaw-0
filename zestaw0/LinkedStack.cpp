#include <iostream>
#include "LinkedStack.hpp"
#include "Node.hpp"

LinkedStack::LinkedStack(int capacity) {

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

        std::cout << x << " dodany do stosu\n";

        size++;
    }   
}

int LinkedStack::linkedPop() {
    if (this->linkedEmpty()) {
        throw std::out_of_range("Stos pusty");
    }
    else {
        Node* temp = head;
        int popped_value = temp->data; // Zapisz wartość do zwrócenia
        head = head->next;
        delete temp;
        size--;
        std::cout << "usunieta wartosc to " << popped_value << "\n";
        return popped_value; // Zwróć wartość
    }
}

int LinkedStack::linkedSize() {
    std::cout << "rozmiar stosu " << size << "\n";
    return size;
}

bool LinkedStack::linkedEmpty() {
    if (size == 0) {
        std::cout << "stos pusty\n";
        return true;
    }
    else {
        std::cout << "stos niepusty\n";
        return false;
    }
}

int LinkedStack::top() {

    if (linkedEmpty()) {
        throw std::out_of_range("Stos pusty");
    }
    return head->data;
}


