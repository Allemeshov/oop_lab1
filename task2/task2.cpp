/*
 *13.	Определить количество элементов в заданном массиве, отличающихся от минимального на 9. Найти максимальный из отрицательных элементов и поменять его местами с последним элементом массива.
 * */

#include "task2.h"

bool task2() {
    int length = enterLength();
    if (length == 0)
        return true;

    std::unique_ptr<double[]> array(new double[length]);

    fillArray(array, length, CONSOLE_TYPE);

    const auto temp = findDifferedNums(array, length);
    std::cout << "Number of elements which differ from the minimum by 9: " << temp
              << std::endl;

    std::cout << "Array before swapping: " << std::endl << std::endl;
    outputArray(array, length);

    swapNumbers(array, length);

    std::cout << "Array after swapping: " << std::endl << std::endl;
    outputArray(array, length);

    return true;
}

int enterLength() {
    int length = -1;

    do {
        std::cout << "Enter length of array(0 - exit): ";
        if (std::cin >> length)
            std::cout << "Length saved" << std::endl;
        else
            std::cout << "Please, enter a positive number";
    } while (length < 0);

    return length;
}

void fillArray(std::unique_ptr<double[]> &array, const int &length, int type) {
    if (type == CONSOLE_TYPE) {

        double glass;
        for (int i = 0; i < length; ++i) {
            std::cout << "Enter array[" << i << "]: ";
            std::cin >> glass;
            array[i] = glass;
        }
    }
}

void outputArray(const std::unique_ptr<double[]> &array, const int &length) {
    std::cout << '\n';
    for (int i = 0; i < length; ++i) {
        std::cout << '\t' << array[i] << std::endl;
    }
    std::cout << std::endl;
}

int findDifferedNums(const std::unique_ptr<double[]> &array, const int &length) {
    double min = array[0];

    for (int i = 1; i < length; ++i) {
        if (array[i] < min)
            min = array[i];
    }

    int counter = 0;
    for (int i = 0; i < length; ++i) {
        double dif = array[i] - min;

        counter += dif == 9;

//        if (dif == 9)
//            counter++;
    }

    return counter;
}

void swapNumbers(std::unique_ptr<double[]> &array, const int &length) {
    int maxId = findMaxNegativeId(array, length);

    double glass = array[length - 1];
    array[length - 1] = array[maxId];
    array[maxId] = glass;
}

int findMaxNegativeId(const std::unique_ptr<double[]> &array, const int &length) {
    double max;
    int maxId;
    bool hasSigned = false;
    for (int i = 0; i < length; ++i) {
        if (array[i] < 0) {
            if (hasSigned && array[i] > max) {
                max = array[i];
                maxId = i;
            } else if (!hasSigned) {
                hasSigned = true;
                max = array[i];
                maxId = i;
            }
        }
    }

    return maxId;
}
