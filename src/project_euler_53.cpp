#include <iostream>

using namespace std;

double factorial(int x)
{
    double res = 1.0;
    for (int i=1; i<=x; i++)
        res *= i;
    return res;
}

double choose(int n, int k)
{
    return factorial(n)/(factorial(k) * factorial(n-k));
}

int main()
{
    int count = 0;
	for (int n=1; n<=100; n++)
    {
        for (int r=0; r<=n; r++)
        {
            if (choose(n, r) > 1000000.0)
                count++;
        }
    }

    cout << count << endl;
}
