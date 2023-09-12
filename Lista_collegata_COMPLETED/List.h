// List.h

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List {
    public:
        List();

        void addNode();
        bool checkPosition(size_t);
        size_t getNodes();
        void deleteNode(size_t);
        void printList();
        
        ~List();

    private:
        Node* head;
};

#endif