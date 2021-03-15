#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	double max = 0;
    int line = 0;

    ifstream file("./data/p099_base_exp.txt");

    int current_line = -1;

    while (!file.eof())
    {
        current_line++;

        int base=0, exponent=0;

        file >> base;
        file.get();
        file >> exponent;
        file.get();

        if (exponent * log(base) > max)
        {
            max = exponent * log(base);
            line = current_line;
        }
    }

    cout << line << endl;
}
