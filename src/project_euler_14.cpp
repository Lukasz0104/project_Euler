#include <iostream>

using namespace std;

int collatz_steps(unsigned long number)
{
    int steps = 0;
    while (number!=1)
    {
        steps++;
        if (number%2 == 0)
        {
            number/=2;
        }
        else
            number = 3 * number+1;
    }
    return steps;
}

int main()
{
    int index = 1;
    int longest = 1;
	for (int i=2; i<1000000; i++)
    {
        int c = collatz_steps(i);
        if (c>longest)
        {
            index = i;
            longest = c;
        }
    }
    cout << index << endl;
}