#include <iostream>

using namespace std;

bool is_prime(unsigned int n)
{
    for (unsigned int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned long long sum = 0;
	for (int i=2; i<2000000; i++)
    {
        if (is_prime(i))
            sum+=i;
    }
    cout << sum << endl;
}