//
// Created by Alexander on 07.09.2021.
//

#ifndef LAB_TEMPLATE_TASK1_H
#define LAB_TEMPLATE_TASK1_H

#include <iostream>
#include <random>
#include <fstream>

bool task1();


int chooseTask1Type();


bool dynamicArrayAppLaunch();

bool STLAppLaunch();

int chooseArrayFillingType();


int *fillWithRandomNumbers(int *array, int &length);

void fillLength(int &length);

int *fillFromConsole(int array[], int &length);

int *fillFromFile(int array[], int &length);

void sortArray(int array[], const int &length);

void removeRepeated(int array[], int &length);

void outputResult(const int array[], const int &length);

void saveResultInFile(const int array[], const int &length);


#endif //LAB_TEMPLATE_TASK1_H
