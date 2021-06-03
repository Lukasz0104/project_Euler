#include <iostream>

#define ull unsigned long long

using namespace std;

unsigned int remainder_mod_a_sq(int a, int n)
{
    unsigned int result1 = 1;
    for (int i=0; i<n; i++)
    {
        result1 = (result1 * (a-1))%(a*a);
    }
    unsigned int result2 = 1;
    for (int i=0; i<n; i++)
    {
        result2 = (result2 * (a+1))%(a*a);
    }
    return (result1 + result2)%(a*a);
}

unsigned int max_remainder(int a)
{
    unsigned int max = 0;
    for (int i=0; i<10000; i++)
    {
        unsigned int x = remainder_mod_a_sq(a, i);
        if (x>max)
            max = x;
    }
    return max;
}

int main()
{
	unsigned long long sum = 0;
    for (int a = 3; a<=1000; a++)
        sum += max_remainder(a);

    cout << sum << endl;
}