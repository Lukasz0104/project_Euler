#include <iostream>

using namespace std;

bool is_pandigital(long long n)
{
    short arr[9];

    int i = 8;
    while (n)
    {
        arr[i] = n%10;
        n/=10;
        i--;
    }

    for (int i=1; i<10; i++)
    {
        bool f = false;
        for (int j=0; j<9; j++)
        {
            if (arr[j] == i)
                f = true;
        }
        if (!f)
            return false;
    }
    return true;
}

int num_of_digits(long long n)
{
    int c = 0;
    do
    {
        c++;
        n/=10;
    } while (n);

    return c;
}

long long concat(int num, int times)
{
    long long r = 0;

    for (int i=1; i<=times; i++)
    {
        int t = num * i;
        for (int j=0; j<num_of_digits(t); j++)
        {
            r*=10;
        }
        r += t;
    }

    return r;
}

int main()
{
    
    long long max = 0;
	for (int n=2; n<10; n++)
    {
        for (int i=1; i<100000; i++)
        {
            long long t = concat(i, n);
            if (is_pandigital(t) && num_of_digits(t)==9 && t>max)
                max = t;
        }
    }

    cout << max << endl;
    
    cout << concat(9, 5) << endl;
}