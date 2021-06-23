#include <iostream>

using namespace std;

bool isPrime(long long n)
{
    if (n==1) return false;
    if (n==2) return true;
    if (n%2 == 0) return false;
    for (int i=3; i*i<=n; i+=2)
    {
        if (n%i==0) return false;
    }
    return true;
}

int main()
{
	auto f1 = [](long long n)
    {
        return 4*n*n - 10*n + 7;
    };
    auto f2 = [](long long n)
    {
        return (2*(n - 1) + 1) * (2*(n-1) + 1);
    };
    auto f3 = [](long long n)
    {
        return 4*n*n - 6*n + 3;
    };
    auto f4 = [](long long n)
    {
        return 4*n*n - 8*n + 5;
    };

    unsigned int row = 1;
    int primeCount = 0;

    do 
    {
        row++;
        if (isPrime(f1(row))) 
        {
            primeCount++;
        }
        if (isPrime(f4(row))) 
        {
            primeCount++;
        }
        if (isPrime(f3(row))) 
        {
            primeCount++;
        }
        if (isPrime(f2(row))) 
        {
            primeCount++;
        }        
    } while (100 * primeCount / (4 * (row-1) + 1) >= 10);
    cout << 2 * row - 1 << endl;
    
    return 0;
}