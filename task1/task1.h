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

void fillWithRandomNumbersSTL(std::vector<int> &array, int &length);

void fillLength(int &length);

int *fillFromConsole(int array[], int &length);

void fillFromConsoleSTL(std::vector<int> &array, int &length);

int *fillFromFile(int array[], int &length);

void fillFromFileSTL(std::vector<int> &array, int &length);

int *rewriteArray(const int *array, int &iter, const int &glass);

void sortArray(int array[], const int &length);

void sortArraySTL(std::vector<int> &array, const int &length);

void removeRepeated(int array[], int &length);

void removeRepeatedSTL(std::vector<int> &array, int &length);

void outputResult(const int array[], const int &length);

void outputResultSTL(const std::vector<int> &array, const int &length);

void saveResultInFile(const int array[], const int &length);

void saveResultInFileSTL(std::vector<int> array, const int &length);


#endif //LAB_TEMPLATE_TASK1_H
