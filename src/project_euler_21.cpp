#include <iostream>

using namespace std;

int sum_of_proper_divisors(int n)
{
    int s = 1;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            s = s + i;
            if (n/i != i)
                s += n/i;
        }
    }
    return s;
}

int main()
{
    unsigned int sum = 0;
	for (int i=2; i<10000; i++)
    {
        int x = sum_of_proper_divisors(i);
        if (sum_of_proper_divisors(x) == i && x!=i)
        {
            sum += i;
        }
    }

    cout << sum << endl;
}