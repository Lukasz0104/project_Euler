#include <iostream>
#define UPPER 10000001
using namespace std;

int num_of_divisors(unsigned int number)
{
    int num_of_divs = 0;
    for (int i=1; i*i<=number; i++)
    {
        if (number%i == 0)
        {
            num_of_divs++;
            if (number/i != i)
                num_of_divs++;
        }
    }
    return num_of_divs;
}

int main()
{
    unsigned int count = 0;
    int prev = num_of_divisors(2);
	for (unsigned int i=3; i<UPPER; i++)
    {
        int x = num_of_divisors(i);
        if (prev == x)
            count++;
        prev = x;
    }

    cout << count << endl;
    
}
