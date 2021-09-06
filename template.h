//
// Created by Alexander Lemeshov.
//

#ifndef LAB_TEMPLATE_TEMPLATE_H
#define LAB_TEMPLATE_TEMPLATE_H

#include <iostream>

#define MALE 0
#define FEMALE 1

void introduce(const std::string &authorsName, const std::string &email, int sex = MALE);

void introduce(const std::string &authorsName, int sex = MALE);


void enterTaskNumber(int &selectedTask, const int &minTaskNumber, const int &maxTaskNumber);


void task1();

void task2();


#endif //LAB_TEMPLATE_TEMPLATE_H
