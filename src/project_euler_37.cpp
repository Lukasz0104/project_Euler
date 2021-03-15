#include <iostream>

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

bool is_right_truncatable(unsigned int n)
{
    if (n<10)
        return is_prime(n);
    return is_prime(n) && is_right_truncatable(n/10);
}

bool is_left_truncatable(unsigned int n)
{
    bool x = is_prime(n);
    if (false == x)
        return false;
    if (n<10)
        return x;
    unsigned int r = n%10;
    unsigned int c = n/10;
    int k = 10;
    while (c>9)
    {
        r += k*(c%10);
        c/=10;
        k*=10;
    }
    return is_left_truncatable(r);
}

int main()
{
    unsigned int sum = 0;
	int count = 0;
    unsigned int p = 11;
    while (count<11)
    {
        if (is_left_truncatable(p) && is_right_truncatable(p))
        {
            count++;
            sum+=p;
        }
        p+=2;
    }
    cout << sum << endl;
}
