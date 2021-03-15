#include <iostream>

#define ull unsigned long long

using namespace std;

int main()
{
	ull a = 1;
    ull x = 600851475143;

    while (x>1)
    {
        a+=2;
        while (x%a == 0)
        {
            x/=a;
        }
    }
    cout << a << endl;
}
