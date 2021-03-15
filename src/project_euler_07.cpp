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
    int prime_count = 0;
    int num = 1;
    while (prime_count < 10001)
    {
        num++;
        if (is_prime(num))
            prime_count++;
    }
	cout << num << endl;
}
