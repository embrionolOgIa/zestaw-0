#include <iostream>
#include "onpstacklib.hpp"
#include "Node.hpp"

onpstacklib::onpstacklib() : head(nullptr), size(0) {}

void onpstacklib::linkedPush(char x) {

    Node* new_node = new Node(x);

    if (!new_node) {
        throw std::out_of_range("Stos pelny");
    }
    else {
        // dolacz nowy node to obecnie ostatniego
        new_node->next = head;

        // nowy node jest teraz ostatni
        head = new_node;

        //std::cout << x << " dodany do stosu\n";

        size++;
    }   
}

char onpstacklib::linkedPop() {
    if (this->linkedEmpty()) {
        throw std::out_of_range("Stos pusty");
    }
    else {
        Node* temp = head;
        char popped_value = temp->data; // Zapisz wartość do zwrócenia
        head = head->next;
        delete temp;
        size--;
        //std::cout << "usunieta wartosc to " << popped_value << "\n";
        return popped_value; // Zwróć wartość
    }
}

int onpstacklib::linkedSize() {
    std::cout << "rozmiar stosu " << size << "\n";
    return size;
}

bool onpstacklib::linkedEmpty() {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

char onpstacklib::top() {

    if (linkedEmpty()) {
        throw std::out_of_range("Stos pusty");
    }
    return head->data;
}


