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

 13.	Удалить из массива повторяющиеся элементы.

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
            break;
        }
        case 1: {
            array = fillWithRandomNumbers(array, length);
            break;
        }
        case 2: {
            array = fillFromConsole(array, length);
            break;
        }
        case 3: {
            array = fillFromFile(array, length);
            break;
        }
        default:
            break;
    }

    if (array == nullptr) {
        isFinished = false;
        return isFinished;
    }

    outputResult(array, length);

    sortArray(array, length);

    outputResult(array, length);

    removeRepeated(array, length);

    outputResult(array, length);
    saveResultInFile(array, length);

    return isFinished;
}

bool STLAppLaunch() {
    bool isFinished = false;
    int fillingType = chooseArrayFillingType();

    int length = 0;
//    int *array = nullptr;
    std::vector<int> array;

    switch (fillingType) {
        case 0: {
            isFinished = true;
            break;
        }
        case 1: {
            fillWithRandomNumbersSTL(array, length);
            break;
        }
        case 2: {
            fillFromConsoleSTL(array, length);
            break;
        }
        case 3: {
            fillFromFileSTL(array, length);
            break;
        }
        default:
            isFinished = true;
            break;
    }

    if (length == 0) {
        isFinished = false;
        return isFinished;
    }

    outputResultSTL(array, length);

    sortArraySTL(array, length);

    outputResultSTL(array, length);

    removeRepeatedSTL(array, length);

    outputResultSTL(array, length);
    saveResultInFileSTL(array, length);

    return isFinished;
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


int *fillWithRandomNumbers(int *array, int &length) {
    fillLength(length);

    array = new int[length];


    for (int i = 0; i < length; ++i) {
        array[i] = getRandNumber();
    }

    return array;
}

void fillWithRandomNumbersSTL(std::vector<int> &array, int &length) {
    fillLength(length);


    for (int i = 0; i < length; ++i) {
//        array[i] = getRandNumber();
        array.push_back(getRandNumber());
    }

//    return array;
}

int getRandNumber() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-100, 100);

    return dist(mt);
}


int *fillFromConsole(int array[], int &length) {
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

    return array;
}

void fillFromConsoleSTL(std::vector<int> &array, int &length) {
    int temp;
    do {
        std::cout << "Введите длину массива: ";
        std::cin >> temp;
    } while (temp <= 0);

    length = temp;

//    array = new int[length];

    for (int i = 0; i < length; ++i) {
        std::cout << "element [" << i << "]: ";
        std::cin >> temp;
        array.push_back(temp);
    }

//    return array;
}


int *fillFromFile(int array[], int &length) {
    std::fstream file;
    std::string filePath;

    array = nullptr;

    std::cin.ignore(1, '\n');
    while (true) {
        std::cout << "Введите имя файла: ";
        std::getline(std::cin, filePath);

        file.open(filePath, std::ios_base::in);

        std::cin.ignore(0);

        if (file.good()) {
            int iter = 0;
            int glass;

            std::string input;

            while (true) {
                std::getline(file, input);

                //TODO Clarify which file parse should be implemented.
                if (input.empty())
                    break;

                glass = std::stoi(input, nullptr, 10);
                array = rewriteArray(array, iter, glass);
            }


            length = iter;
            return array;
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

    file.close();

    return array;
}

void fillFromFileSTL(std::vector<int> &array, int &length) {
    std::fstream file;
    std::string filePath;

    std::cin.ignore(1, '\n');
    while (true) {
        std::cout << "Введите имя файла: ";
        std::getline(std::cin, filePath);

        file.open(filePath, std::ios_base::in);

        std::cin.ignore(0);

        if (file.good()) {
            int iter = 0;
            int glass;

            std::string input;

            while (true) {
                std::getline(file, input);

                //TODO Clarify which file parse should be implemented.
                if (input.empty())
                    break;

                glass = std::stoi(input, nullptr, 10);
                array.push_back(glass);
                iter++;
            }


            length = iter;
            break;
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

    file.close();
}

int *rewriteArray(const int *arr, int &iter, const int &glass) {
    int *result = new int[iter + 1];
    for (int i = 0; i < iter; ++i) {
        result[i] = arr[i];
    }
    result[iter++] = glass;

    delete[] arr;
    return result;
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
    int glass;

    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j + 1] < array[j]) {
                glass = array[j + 1];
                array[j + 1] = array[j];
                array[j] = glass;
            }
        }
    }
}

void sortArraySTL(std::vector<int> &array, const int &length) {
    int glass;

    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j + 1] < array[j]) {
                glass = array[j + 1];
                array[j + 1] = array[j];
                array[j] = glass;
            }
        }
    }
}

void removeRepeated(int array[], int &length) {
    if (length == 0 || length == 1)
        return;

    int temp[length];

    int i;
    int j = 0;
    for (i = 0; i < length - 1; ++i) {
        if (array[i] != array[i + 1]) {
            temp[j++] = array[i];
        }
    }

    temp[j++] = array[length - 1];

    for (i = 0; i < j; ++i) {
        array[i] = temp[i];
    }

    length = j;
}

void removeRepeatedSTL(std::vector<int> &array, int &length) {
    if (length == 0 || length == 1)
        return;

    int temp[length];

    int i;
    int j = 0;
    for (i = 0; i < length - 1; ++i) {
        if (array[i] != array[i + 1]) {
            temp[j++] = array[i];
        }
    }

    temp[j++] = array[length - 1];

    for (i = 0; i < j; ++i) {
        array[i] = temp[i];
    }

    length = j;
}

void outputResult(const int array[], const int &length) {
    for (int i = 0; i < length; ++i) {
        std::cout << "array[" << i << "]: " << array[i] << std::endl;
    }
    std::cout << std::endl;
}

void outputResultSTL(const std::vector<int> &array, const int &length) {
    for (int i = 0; i < length; ++i) {
        std::cout << "array[" << i << "]: " << array[i] << std::endl;
    }
    std::cout << std::endl;
}

void saveResultInFile(const int array[], const int &length) {
    std::fstream file;
    std::string filePath;
    bool isFileFound;
    bool fileWasCreated = false;

    std::cin.ignore(1, '\n');
    while (true) {
        std::cout << "Введите имя нового файла: ";
        std::getline(std::cin, filePath);

        file.open(filePath);

        isFileFound = file.good();

        if (!isFileFound) {
            file.open(filePath, std::ios_base::out);
            isFileFound = file.good();
            fileWasCreated = true;
        } else {
            file.open(filePath, std::ios_base::out | std::ios_base::trunc);
        }

        std::cin.ignore(0);

        if (isFileFound) {
            for (int i = 0; i < length; ++i) {
                file << array[i] << std::endl;
            }
            std::string status = fileWasCreated ? "сохранён" : "обновлён";
            std::cout << "\n\n\tФайл был успешно " << status
                      << " в файл по пути: "
                      << filePath << std::endl;
            break;
        } else {
            std::cout << "Не удалось создать новый файл по данному пути: "
                      << filePath << std::endl;
            do {
                std::cout << "Хотите повторить ввод? [yes / no]: ";
                std::getline(std::cin, filePath);
            } while (filePath != "yes" && filePath != "no");

            if (filePath == "no")
                break;
        }
    }

    file.close();
}

void saveResultInFileSTL(std::vector<int> array, const int &length) {
    std::fstream file;
    std::string filePath;
    bool isFileFound;
    bool fileWasCreated = false;

    std::cin.ignore(1, '\n');
    while (true) {
        std::cout << "Введите имя нового файла: ";
        std::getline(std::cin, filePath);

        file.open(filePath);

        isFileFound = file.good();

        if (!isFileFound) {
            file.open(filePath, std::ios_base::out);
            isFileFound = file.good();
            fileWasCreated = true;
        } else {
            file.open(filePath, std::ios_base::out | std::ios_base::trunc);
        }

        std::cin.ignore(0);

        if (isFileFound) {
            for (int i = 0; i < length; ++i) {
                file << array[i] << std::endl;
            }
            std::string status = fileWasCreated ? "сохранён" : "обновлён";
            std::cout << "\n\n\tФайл был успешно " << status
                      << " в файл по пути: "
                      << filePath << std::endl;
            break;
        } else {
            std::cout << "Не удалось создать новый файл по данному пути: "
                      << filePath << std::endl;
            do {
                std::cout << "Хотите повторить ввод? [yes / no]: ";
                std::getline(std::cin, filePath);
            } while (filePath != "yes" && filePath != "no");

            if (filePath == "no")
                break;
        }
    }

    file.close();
}