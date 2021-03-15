#include <iostream>

using namespace std;

bool is_pentagonal(int n)
{
    int i = 0;
    while(n >= (i+1) * (3*(i+1) - 1) / 2)
    {
        i++;
    }
    if (i*(3*i-1)/2 == n)
    {
        return true;
    }
    return false;
}

int pentagonal(int n)
{
    return n * (3*n - 1)/2;
}

int main()
{   
    int a = 2;
    while (true)
    {
        for (int b =1; b<a; b++)
        {
            int pa = pentagonal(a);
            int pb = pentagonal(b);

            if (is_pentagonal(pa+pb) && is_pentagonal(abs(pa-pb)))
            {
                cout << abs(pa-pb)<<endl;
                return 0;
            }
        }
        a++;
    }
}
