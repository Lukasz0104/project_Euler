#include <iostream>
#include <vector>

#define UPPER 1000000

using namespace std;

bool is_prime(unsigned int n)
{
    if (n<2)
        return false;
    
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
	vector<int> primes = {2};

    for (int i=3; i<UPPER; i+=2)
    {
        if (is_prime(i))
            primes.push_back(i);
    }

    for (int len = 546; len>2; len--)
    {
        for (int i=0; i<primes.size() - len; i++) //start
        {
            int sum = 0;
            for (int j=0; j<len; j++)
            {
                sum+=primes[i+j];
            }

            if (is_prime(sum) && sum < UPPER)
            {
                cout << sum << endl;
                return 0;
            }
        }
    }
}
