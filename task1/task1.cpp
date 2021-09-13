//
// Created by Alexander on 07.09.2021.
//

/*
 * 1)	Описать динамический массив целых чисел (количество элементов указывает пользователь), для выделения памяти использовать операцию new, для очищения памяти использовать delete
2)	Все данные передаются в функции в виде параметров, глобальные переменные использовать запрещено; все дальнейшие пункты требований реализованы в виде отдельной функции.
3)	Заполнить массив в зависимости от выбора способа пользователем:
a.	 случайными числами (отдельная функция  с аргументами: указатель на массив, количество элементов (по умолчанию 10)
b.	Вручную
c.	Из файла (имя файла вводит пользователь)
4)	Выполнить сортировку массива
5)	Выполнить действия согласно варианту.
6)	Результат вывести на экран и сохранить в файл (описать функцию сохранения массива в файл с аргументами: массив, количество элементов, имя файла). http://cppstudio.com/post/446/
7)	Аналогичные действия выполнить средствами STL vector в отдельной программе.
8)	Результат выполнения задания – 2 программы (динамический массив и STL).
*/

#include "task1.h"

int getRandNumber();

bool task1() {
    int type = chooseTask1Type();
    bool isFinished = false;

    switch (type) {
        case 0: {
            isFinished = true;
        }
        case 1: {
            isFinished = dynamicArrayAppLaunch();
            break;
        }
        case 2: {
            isFinished = STLAppLaunch();
            break;
        }
        default:
            break;
    }

    std::cout << "\n\tПрограмма закончила выполнение." << std::endl;
    return isFinished;
}

int chooseTask1Type() {
    int res = -1;

    while (true) {
        std::cout << "Какой вариант программы запустить?" << std::endl;
        std::cout << "1 - динамический массив." << std::endl;
        std::cout << "2 - STL." << std::endl;
        std::cout << "0 - Завершить приложение." << std::endl;
        std::cout << "Вариант (укажите цифру): " << std::endl << std::endl;
        std::cin >> res;

        if (res == 0) {
            res = false;
        } else if (1 <= res && res <= 2) {
            std::cout << "\tВыбран номер задания: " << res << std::endl;
            break;
        } else {
            std::cout << "\tНомер задания некорректный! Повторите ввод." << std::endl << std::endl;
        }
    }

    return res;
}


bool dynamicArrayAppLaunch() {
    bool isFinished = false;
    int fillingType = chooseArrayFillingType();

    int length;
    int *array = nullptr;

    switch (fillingType) {
        case 0: {
            isFinished = true;
            break;
        }
        case 1: {
            array = (int *) fillWithRandomNumbers(array, length);
            break;
        }
        case 2: {
            fillFromConsole(array, length);
            break;
        }
        case 3: {
            fillFromFile(array, length);
            break;
        }
        default:
            break;
    }

    sortArray(array, length);

    outputResult(array, length);
    saveResultInFile(array, length);

    return isFinished;
}

bool STLAppLaunch() {

}


int chooseArrayFillingType() {
    int res = -1;

    while (true) {
        std::cout << "Какой тип заполнения массива выбрать?" << std::endl;
        std::cout << "1 - Случайными числами." << std::endl;
        std::cout << "2 -  Вручную." << std::endl;
        std::cout << "3 -  Из файла." << std::endl;
        std::cout << "0 - Завершить приложение." << std::endl;
        std::cout << "Вариант (укажите цифру): " << std::endl << std::endl;
        std::cin >> res;

        if (0 <= res && res <= 3) {
            std::cout << "\tВыбран номер задания: " << res << std::endl;
            break;
        } else {
            std::cout << "\tНомер типа некорректный! Повторите ввод." << std::endl << std::endl;
        }
    }

    return res;
}


void *fillWithRandomNumbers(int array[], int &length) {
    fillLength(length);

    array = new int[length];

    //    TODO

    for (int i = 0; i < length; ++i) {
        array[i] = getRandNumber();
    }

    return array;
}

int getRandNumber() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-100, 100);

    return dist(mt);
}


void fillFromConsole(int array[], int &length) {
    int temp;
    do {
        std::cout << "Введите длину массива: ";
        std::cin >> temp;
    } while (temp <= 0);

    length = temp;

    array = new int[length];

    for (int i = 0; i < length; ++i) {
        std::cout << "element [" << i << "]: ";
        std::cin >> array[i];
    }
}

void fillFromFile(int array[], int &length) {
    std::fstream file;
    std::string filePath;

    while (true) {
        std::cout << "Введите имя файла: ";
        std::getline(std::cin, filePath);

        file.open(filePath, std::ios_base::in);

        if (file.good()) {
            int iter = 0;
            int glass;
            while (file >> glass) {
                delete array;

                array = new int[iter + 1];
                array[iter++] = glass;
            }

            length = iter;
        } else {
            std::cout << "Не удалось прочитать файл по данному пути: " << filePath << std::endl;

            do {
                std::cout << "Хотите повторить ввод? [yes / no]: ";
                std::getline(std::cin, filePath);
            } while (filePath != "yes" && filePath != "no");

            if (filePath == "no")
                break;
        }
    }
}

void fillLength(int &length) {
    std::string answer;
    while (answer != "да" && answer != "нет") {
        std::cout << "Хотите вручную ввести длину массива? (По умолчанию 10) [да / нет]: ";
        std::cin >> answer;
    }

    if (answer == "да") {
        std::cout << "Длина массива: ";
        std::cin >> length;
    } else {
        length = 10;
    }
}


void sortArray(int array[], const int &length) {
    for (int i = 0; i < length; ++i) {
        std::cout << array[i] << std::endl;
    }
}

void outputResult(const int array[], const int &length) {

}

void saveResultInFile(const int array[], const int &length) {

}