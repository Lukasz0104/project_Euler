#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n<2) return false;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int count_primes(int a, unsigned int b)
{
    int n = 0;
    while( is_prime(n*n +a*n + b) )
    {
        n++;
    }
    return n;
}

int main()
{
	int max_primes = 0;
    int max_a;
    int max_b;
    for (int a=-999; a<1000; a++)
    {
        for (int b=0; b<=1000; b++)
        {
            int c = count_primes(a,b);
            if (c>max_primes)
            {
                max_primes = c;
                max_a = a;
                max_b = b;
            }
        }
    }
    cout << "a: " << max_a << endl;
    cout << "b: " << max_b << endl;
    cout << "most primes: " << max_primes << endl;
    cout << max_a * max_b << endl;
}
