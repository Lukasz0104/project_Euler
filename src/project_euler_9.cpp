#include <iostream>

using namespace std;

int main() 
{
    for (int a=1;a<998;a++)
    {
        for (int b=a;b<998-a;b++)
        {
            if (a*a +b*b == (1000-a-b)*(1000-a-b))
            {
                cout << a*b*(1000-a-b)<<endl;
            }
        }
    }
    return 0;
}