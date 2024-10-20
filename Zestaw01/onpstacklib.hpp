#include <iostream>
#include <stdexcept>
#include "Node.hpp"

class onpstacklib {

    Node* head;

private:
    int size = 0;

public:
    onpstacklib(); // Konstruktor. Argumentem jest rozmiar tablicy.
    void linkedPush(char x); // Wstawia element na stos
    char linkedPop(); // Usuwa element ze stosu i zwraca jego wartość
    int linkedSize(); // Zwraca liczbę elementów na stosie
    bool linkedEmpty(); // Sprawdza czy stos jest pusty
    char top(); //zwraca wartosc z gory stosu (ostatnie zad)

    friend class Node;
};
