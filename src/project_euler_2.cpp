#include <iostream>

using namespace std;

int main()
{
	int a = 1;
    int b = 2;
    int s = 0;

    while (a<=4000000)
    {
        int t = a+b;
        a = b;
        b = t;
        if (a%2 == 0)
        {
            s+=a;
        }
    }
    cout << s << endl;
}