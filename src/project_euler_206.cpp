#include <iostream>

using namespace std;

int main()
{
	for (unsigned long long i = 1000000000; i<=1389026623; i+=10)
    {
        unsigned long long x = i*i;
        int arr[] = {0,9,8,7,6,5,4,3,2,1};
        int k = 0;
        bool f = true;
        while (x && f)
        {
            if (x%10!=arr[k])
            {
                f = false;
                break;
            }
            k++;
            x/=100;
        }
        if (f)
            cout << i << endl;
    }
}