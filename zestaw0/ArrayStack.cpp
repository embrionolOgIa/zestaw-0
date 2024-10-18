#include "ArrayStack.hpp"
#include <iostream>

Stack::Stack(int capacity) {

    this->capacity = capacity;
    arr = new int[capacity];
    top = -1;
}

// Wstawia element na stos
void Stack::push(int x) {

    if (full()) {
        throw std::out_of_range("Stos pelny");
    }

    arr[++top] = x;
    std::cout << x << " dodany do stosu\n";
}

// Usuwa element ze stosu i zwraca jego wartość
int Stack::pop() {

    if (empty()) {
        throw std::out_of_range("Stos pusty");
    }
    return arr[top-1];
}

// Zwraca liczbę elementów na stosie
int Stack::size() {
    std::cout << top+1 << " rozmiar stosu\n";
    return top + 1;
}

// Sprawdza czy stos jest pusty
bool Stack::empty() {

    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

// Sprawdza czy stos jest pełny
bool Stack::full() {

    if (top == capacity - 1) {
        return true;
    }
    else {
        return false;
    }
}

