#include <iostream>

using namespace std;

unsigned int digit_fith_power(int n)
{
    unsigned int res = 0;
    while (n)
    {
        int digit = n%10;
        res += digit*digit*digit*digit*digit;
        n/=10;
    }
    return res;
}

int main()
{
    unsigned int sum = 0;
	for (unsigned int i=2; i<10000000; i++)
    {
        if (i == digit_fith_power(i))
            sum += i;
    }

    cout << sum << endl;
}