#include <iostream>

using namespace std;

bool is_prime(long long n)
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


bool is_n_pandigital(long long number, int n)
{
    bool arr[n] = {false};
    while (number)
    {
        int k = number%10;
        if (k>n || k==0)
            return false;
        arr[k-1] = true;
        number/=10;
    }
    for (int i=0; i<n; i++)
    {
        if (false == arr[i])
            return false;
    }
    return true;
}

int num_of_digits(long long n)
{
    int c = 0;
    do
    {
        c++;
        n/=10;
    } while (n);

    return c;
}

int main()
{
	long long largest = 2143;
    long long upper = 987654321;
    long long lower = 100000000;
    for (int n = 9; n>0; n--)
    {
        for (long long i=upper; i>lower; i-=2)
        {
            if (is_n_pandigital(i, n) && is_prime(i))
            {
                cout << i << endl;
                return 0;
            }
        }
        upper %= lower;
        lower /= 10;
    }
}
