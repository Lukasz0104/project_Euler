#include <iostream>

using namespace std;

int main()
{
	long long result = 28433;

    for (int i=0; i<7830457; i++)
    {
        result = (result * 2)%10000000000;
    }

    cout << result + 1 << endl;
}
