#include <iostream>

using namespace std;

int main()
{
    long long r = 0;
	for (int i=1; i<=1000; i++)
    {
        long long k = 1;
        for (int j=0; j<i; j++)
        {
            k = (k*i) % 10000000000;
        }
        r = (r + k)%10000000000;
    }
    cout << r << endl;
}