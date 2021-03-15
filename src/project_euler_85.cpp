#include <iostream>
#include <cmath>

using namespace std;

unsigned int count_rectangles(int a, int b)
{
    int count = 0;
    for (int i=1; i<=a; i++)
    {
        for (int j=1; j<=b; j++)
        {
            count += (a + 1 - i) * (b + 1 - j);
        }
    }
    return count;
}

int main()
{
    unsigned int min_difference = 34;
    int min_a = 636;//400;
    int min_b = 76;//119;
    for (int i=1; i<=10000; i++)
    {
        for (int j=1; j<=i; j++)
        {
            unsigned int x = count_rectangles(i,j);
            if (x > 2001000)
                break;
            unsigned int diff = abs(2000000 - int(x));
            if (diff < min_difference)
            {
                min_difference = diff;
                min_a = i;
                min_b = j;
            }
        }
    }
    cout << min_a * min_b << endl;
}
