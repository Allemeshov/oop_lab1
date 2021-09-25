//
//  Created by Alexander Lemeshov.
//

#include <iostream>
#include "template.h"
#include "task1/task1.h"
#include "task2/task2.h"


int main() {
    introduce("Александр Лемешов", "allemeshov@gmail.com");

    int selectedTask = -1;

    int minTaskNumber = 1;// Enter here minimum task number
    int maxTaskNumber = 2;// Enter here maximum task number

    enterTaskNumber(selectedTask, minTaskNumber, maxTaskNumber);

    int res;

    while (true) {
        switch (selectedTask) {
            case 1:
                res = task1();
                break;
            case 2:
                task2();
                break;
            default:
                break;
        }

        if (!res) {
            std::cout << "\n\tПрограмма была завершена пользователем. Выход из приложения..."
                      << std::endl;
            break;
        }
    }

    return 0;
}


