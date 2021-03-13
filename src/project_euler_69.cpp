#include <iostream>
#define UPPER 1000000

using namespace std;

int *PRIMES;

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

int phi(int n)
{
    if (is_prime(n))
        return n-1;
    
    int i = 0;
    int result = n;
    while (n>1)
    {
        int p = PRIMES[i];
        if (n%p==0)
        {
            n/=p;
            while (n%p == 0)
            {
                n/=p;
            }
            result = result * (1.0 - 1.0/p);
        }
        i++;
    }
    return result;
}

int main()
{
    PRIMES = new int[78498]; //prime nubmers less than 10^6
    int c = 0;
    for (int i=2; i<1000000; i++)
    {
        if (is_prime(i))
            PRIMES[c++] = i;
    }
    
    double max = 0;
    int index = 0;
    for (int i=2; i<=UPPER; i++)
    {
        int x = phi(i);
        if (1.0 * i / x > max)
        {
            max = 1.0 * i / x;
            index = i;
        }
    }
    cout << index << endl;
    
    delete[] PRIMES;
}