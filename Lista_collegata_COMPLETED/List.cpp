// List.cpp

#include <iostream>
#include "List.h"
#include "Node.h"

List::List() : head(nullptr) {}

void List::addNode(){
    Node* newNode = new Node();

    if(!head) {
        head = newNode;
    } else {
        Node* current = head;
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->value = current->value + 1;
    }
}

size_t List::getNodes() {
    Node* current = head;

    if (!current) {
        return 0;
    } else {
        size_t i = 0;

        while (current) {
            i++;
            current = current->next;
        }
        return i;
    }
}

bool List::checkPosition(size_t position) {
    Node* current = head;

    while (current) {
        if (current->value >= position)
            return true;

        current = current->next;
    }

    return false;
}

void List::deleteNode(size_t value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current && current->value != value) {
        previous = current;
        current = current->next;
    }

    if (current) {
        if (previous) {
            previous->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    }

    if (previous) {
        current = previous->next;
    } else {
        current = head;
    }

    while (current) {
        current->value = value;
        current = current->next;
        value++;
    }
}

void List::printList() {
    Node* current = head;

    if (!current) {
        std::cout << "Non sono presenti elementi nella lista." << std::endl;
    } else {
        while (current) {
            std::cout << "Nodo: " << current->value << std::endl;
            current = current->next;
        }
    }
}

List::~List() {
    Node* current = head;
    while (current) {
        Node* toBeDeleted = current;
        current = current->next;
        delete toBeDeleted;
    }
}
