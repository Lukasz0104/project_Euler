#include <iostream>

using namespace std;

int num_of_divisors(unsigned int number)
{
    int num_of_divs = 0;
    for (int i=1; i*i<=number; i++)
    {
        if (number%i == 0)
        {
            num_of_divs+=2;
        }
    }
    return num_of_divs;
}

int main()
{
    unsigned int i = 1;
    while (num_of_divisors(i*(i+1)/2) < 500)
    {
        i++;
    }
    cout << i*(i+1)/2 << endl;
}
