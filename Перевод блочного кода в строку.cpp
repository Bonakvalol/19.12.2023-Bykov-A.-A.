#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("in.txt");
    string line, result;
    cout << in.is_open() << endl;

    while (getline(in, line))
    {
        cout << line << endl;
        for (char elen : line)
        {
            if (elen == '"')
            {
                result += "\\";
            }
            if (elen == '\t')
            {
                result += "\\t";
            }
            else
            {
                result += elen;
            }
        }
        result += "\\n";
    }
    ofstream out("outputCode.txt");
    out << result;
}