#include <iostream>

using namespace std;

int num_of_digits(unsigned int n)
{
    int c = 0;
    do
    {
        c++;
        n/=10;
    } while (n);

    return c;
}

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

bool is_circular_prime(unsigned int n)
{
    const int d = num_of_digits(n);
    int div = 1;
    for (int i=1; i<d; i++)
    {
        div*=10;
    }

    for (int i=1; i<d; i++)
    {
        int t = n/div;
        n = (n%div)*10 + t;
        if (num_of_digits(n)!=d || !is_prime(n))
            return false;
    }
    return true;
}

int main()
{
	int count = 1;
    for (int i=3; i<1000000; i+=2)
    {
        if (is_prime(i) && is_circular_prime(i))
        {
            count++;
            //cout << i << endl;
        }
    }
    cout << count << endl;
}
