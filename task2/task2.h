//
// Created by Alexander on 21.09.2021.
//

#ifndef LAB_1_TASK2_H
#define LAB_1_TASK2_H

#include <iostream>
#include <memory>

#define CONSOLE_TYPE 1

bool task2();

int enterLength();

void fillArray(std::unique_ptr<double[]> &array, const int &length, int type = CONSOLE_TYPE);

int findDifferedNums(const std::unique_ptr<double[]> &array, const int &length);

void outputArray(const std::unique_ptr<double[]> &array, const int &length);

void swapNumbers(std::unique_ptr<double[]> &array, const int &length);

int findMaxNegativeId(const std::unique_ptr<double[]> &array, const int &length);

#endif //LAB_1_TASK2_H
