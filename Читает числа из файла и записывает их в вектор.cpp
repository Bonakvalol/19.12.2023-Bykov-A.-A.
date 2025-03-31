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
        cerr << "������: �� ������� ������� ���� variant27.txt!" << endl;
        return 1;
    }

    string buffer;
    while (getline(file, buffer)) {
        int n = stoi(buffer);
        number.push_back(n);
    }
    file.close();

    if (number.empty()) {
        cerr << "������: ���� ����!" << endl;
        return 1;
    }

    // ����� ������������� �����
    int max = number[0];
    for (int i = 0; i < number.size(); i++) {
        if (number[i] > max) {
            max = number[i];
        }
    }
    cout << "������������ �����: " << max << endl;

    // ����� ������ ������ ������������� �����
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == max) {
            cout << "����� ������ ����. �����: " << (i + 1) << endl;
        }
    }

    // ����� ���� ������ �����
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
        cout << "�� ������� ���� ������� �����" << endl;
    }
    else {
        int pr = 1;
        for (int i = zero1 + 1; i < zero2; i++) {
            pr *= number[i];
        }
        cout << "������������ ����� ����� ������� ����� ������: " << pr << endl;
    }

    // ������ � ����: ������� ������ �������, ����� ��������
    for (int i = 0; i < number.size(); i += 2) {
        outfile << number[i] << endl;
    }
    for (int i = 1; i < number.size(); i += 2) {
        outfile << number[i] << endl;
    }

    outfile.close();
    return 0;
}
