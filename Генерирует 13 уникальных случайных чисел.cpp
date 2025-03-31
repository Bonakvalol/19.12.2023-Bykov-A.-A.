#include <iostream> 
#include <ctime> 
#include <fstream> 
#include <vector> 
using namespace std;
int peremeh(vector<int>& vopros1) {
    while (vopros1.size() < 13) {
        int random_number = (rand() % 13) + 1;
        bool duplicate = false;
        for (int num : vopros1) {
            if (num == random_number) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            vopros1.push_back(random_number);
        }
    }
    return 0;
}
int newotveti(vector<int>otveti, vector<int>vopros1) {
    ofstream outputFile("otveti_new.txt");
    for (int i = 0; i < vopros1.size(); i++) {
        int g = vopros1[i];
        outputFile << otveti[g - 1] << endl;
    }
    outputFile.close();
    return 0;
}
int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    vector<int>vopros1;
    vector<int>otveti;
    ifstream file("otveti_base.txt");
    int num;
    while (file >> num) {
        otveti.push_back(num);
    }
    file.close();
    peremeh(vopros1);
    newotveti(otveti, vopros1);
    for (int i = 0; i < otveti.size(); i++) {
        cout << vopros1[i] << endl;
    }



}