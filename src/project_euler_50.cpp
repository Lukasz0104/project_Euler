#include <iostream>
#include <vector>
#include <algorithm>

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
	vector<int> primes;

    for (int i=2; i<1000; i++)
    {
        if (is_prime(i))
            primes.push_back(i);
    }

    for (int i=primes.size()-1;i>=0; i--)
    {
        int sum=0;
        for (int j=0; j<=i; j++)
        {
            sum+=primes[j];
        }
        if (find(primes.begin(), primes.end(), sum)!=primes.end())
        {
            cout << sum << endl;
        }
    }
}