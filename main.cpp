//
//  Created by Alexander Lemeshov.
//

#include <iostream>
#include "template.h"


int main() {
    introduce("Александр Лемешов", "allemeshov@gmail.com");

    int selectedTask = -1;

    int minTaskNumber = 1;// Enter here minimum task number
    int maxTaskNumber = 2;// Enter here maximum task number

    enterTaskNumber(selectedTask, minTaskNumber, maxTaskNumber);

    switch (selectedTask) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        default:
            break;
    }

    return 0;
}


void task1() {
    // Something...
    std::cout << "task 1";
}

void task2() {
    // Something...
    std::cout << "task 2";
}

