#include <iostream>

using namespace std;

int main()
{
    int m = 0;
    int max_p = 0;
    for (int p=3; p<1001; p++)
    {
        int c = 0;
        for (int a=1; a<p-2; a++)
        {
            for (int b=a; b<p-2-a; b++)
            {
                if (a*a + b*b == (p-a-b)*(p-a-b))
                c++;
            }
        }
        if (c>m) 
        {
            m = c;
            max_p = p;
        }
    }
    cout << max_p << endl;

}