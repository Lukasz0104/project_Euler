#include <iostream>
#include <vector>

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

bool satisfies_goldbachs_other_conjecture(unsigned int n, const vector<int> &primes_up_to_n)
{
    for (int i=primes_up_to_n.size() - 1; i>=0; i--)
    {
        int j;
        for (j=1; (primes_up_to_n[i] + 2*j*j)<n; )
            j++;
        if (primes_up_to_n[i] + 2*j*j == n)
            return true;
    }

    return false;
}

int main()
{
	unsigned int i = 9;

    vector<int> primes = {2,3,5,7};

    while (true)
    {
        if (is_prime(i))
            primes.push_back(i);
        else if (!satisfies_goldbachs_other_conjecture(i, primes))
            break;
        i+=2;
    }

    cout << i << endl;
}
