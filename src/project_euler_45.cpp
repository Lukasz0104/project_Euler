#include <iostream>

using namespace std;

bool is_triangular(unsigned int n)
{
    unsigned int i = 1;
    while ((i * (i+1)/2) < n)
        i++;
    return n == (i * (i+1)/2);
}

bool is_pentagonal(unsigned int n)
{
    unsigned int i = 1;
    while (i * (3*i - 1)/2 < n)
    {
        i++;
    }
    return (i * (3*i - 1)/2) == n;
}

int main()
{
	for (int i=144; ; i++)
    {
        unsigned int x = i * (2*i - 1);
        if (is_pentagonal(x) && is_triangular(x))
        {
            cout << x << endl;
            break;
        }
    }
}
