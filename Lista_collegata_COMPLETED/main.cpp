// main.cpp

#include <iostream>
#include "List.h"

int main(){
    std::cout << "Deucan" << std::endl;

    List myList;

    while(true) {
        char input {'k'};

        std::cout << std::endl;

        std::cout << "Press A to add a new node." << std::endl;
        std::cout << "Press D to delete a node." << std::endl;
        std::cout << "Press P to see the list." << std::endl;
        std::cout << "Press E to exit." << std::endl;

        std::cout << "Press: ";
        std::cin >> input;

        std::cout << std::endl;
        std::cout << std::endl;

        if (input == 'e' || input == 'E'){
            std::cout << "Thank you!!" << std::endl;
            break;
        }

        switch (input) {
            case 'a':
            case 'A':
                myList.addNode();
                std::cout << "Node added." << std::endl;
                break;

            case 'd':
            case 'D':
                
                if (myList.getNodes() == 0) {
                    std::cout << "Non sono presenti elementi nella lista." << std::endl;
                    break;
                } else {
                    size_t position;
                    std::cout << "Select the position: ";
                    std::cin >> position;
                    std::cout << std::endl;

                    if (!myList.checkPosition(position)) {
                        std::cout << "Invalid number." << std::endl;
                        break;
                    }

                    myList.deleteNode(position);
                    std::cout << "Node deleted." << std::endl;
                }
                break;
            
            case 'p':
            case 'P':
                myList.printList();
                break;

            default:
                std::cout << "Press a correct charatcter." << std::endl;
                break;
        }
    }

    return 0;
}