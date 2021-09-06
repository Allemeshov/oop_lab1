//
// Created by Alexander on 06.09.2021.
//

#include "template.h"


void introduce(const std::string &authorsName, int sex) {
    std::cout << "\n\n\tПриветствую!\n\n";

    std::cout << '\t' << authorsName << " выполнил";
    if (sex == FEMALE) std::cout << 'a';
    std::cout << " данную лабораторную работу.\n\n";
}

void introduce(const std::string &authorsName, const std::string &email, int sex) {
    std::cout << "\n\n\tПриветствую!\n\n";

    std::cout << '\t' << authorsName << " выполнил";
    if (sex == FEMALE) std::cout << 'a';
    std::cout << " данную лабораторную работу.\n\n";

    std::cout << '\t' << "По всем вопросам прошу обращаться по данному адресу: " << email
              << std::endl << std::endl << std::endl;

}


void enterTaskNumber(int &selectedTask, const int &minTaskNumber, const int &maxTaskNumber) {
    while (true) {
        std::cout << "Введите номер задания: ";
        std::cin >> selectedTask;

        if (minTaskNumber <= selectedTask && selectedTask <= maxTaskNumber) {
            std::cout << "Номер задания корректный."
                      << std::endl << std::endl << std::endl << std::endl;
            break;
        } else {
            std::cout << "Номер задания некоректный! Выберите от " << minTaskNumber << " до " << maxTaskNumber
                      << " (включительно)" << std::endl;
        }
    }
}

