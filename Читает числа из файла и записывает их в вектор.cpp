#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> number;
    ifstream file("variant27.txt");
    ofstream outfile("out27.txt");

    if (!file) {
        cerr << "Ошибка: не удалось открыть файл variant27.txt!" << endl;
        return 1;
    }

    string buffer;
    while (getline(file, buffer)) {
        int n = stoi(buffer);
        number.push_back(n);
    }
    file.close();

    if (number.empty()) {
        cerr << "Ошибка: файл пуст!" << endl;
        return 1;
    }

    // Поиск максимального числа
    int max = number[0];
    for (int i = 0; i < number.size(); i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }
    cout << "Максимальное число: " << max << endl;

    // Поиск номера строки максимального числа
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == max) {
            cout << "Номер строки макс. числа: " << (i + 1) << endl;
        }
    }

    // Поиск двух первых нулей
    int zero1 = -1, zero2 = -1;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == 0) {
            if (zero1 == -1) {
                zero1 = i;
            }
            else {
                zero2 = i;
                break;
            }
        }
    }

    if (zero1 == -1 || zero2 == -1) {
        cout << "Не найдено двух нулевых чисел" << endl;
    }
    else {
        int pr = 1;
        for (int i = zero1 + 1; i < zero2; i++) {
            pr *= number[i];
        }
        cout << "Произведение чисел между первыми двумя нулями: " << pr << endl;
    }

    // Запись в файл: сначала четные индексы, потом нечетные
    for (int i = 0; i < number.size(); i += 2) {
        outfile << number[i] << endl;
    }
    for (int i = 1; i < number.size(); i += 2) {
        outfile << number[i] << endl;
    }

    outfile.close();
    return 0;
}
