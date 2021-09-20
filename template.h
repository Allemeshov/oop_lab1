//
// Created by Alexander Lemeshov.
//

#ifndef LAB_TEMPLATE_TEMPLATE_H
#define LAB_TEMPLATE_TEMPLATE_H

#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <term.h>

using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

#define MALE 0
#define FEMALE 1

void introduce(const std::string &authorsName, const std::string &email, int sex = MALE);

void introduce(const std::string &authorsName, int sex = MALE);


void enterTaskNumber(int &selectedTask, const int &minTaskNumber, const int &maxTaskNumber);

#endif //LAB_TEMPLATE_TEMPLATE_H
