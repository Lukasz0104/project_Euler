#include <iostream>

using namespace std;

int distinct_prime_factors(int n)
{
    int count = 0;

    if (n%2 == 0)
        count++;

    while (n%2 == 0)
        n/=2;
    
    for (int i=3; i <= n; i+=2)
    {
        if (n%i == 0)
            count++;
        while (n%i==0)
            n/=i;
    }
    return count;
}

int main()
{
	int a = distinct_prime_factors(2);
    int b = distinct_prime_factors(3);
    int c = distinct_prime_factors(4);
    int d = distinct_prime_factors(5);
    
    int i = 2;
    while (a!=4 || b!=4 || c!=4 || d!=4)
    {
        a = b;
        b = c;
        c = d;
        d = distinct_prime_factors(i+4);
        i++;
    }
    cout << i << endl;
}