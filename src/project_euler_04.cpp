#include <iostream>

using namespace std;

bool is_palindrome(int number)
{
    int copy = number;
    int c = 0;
    while (copy)
    {
        c++;
        copy/=10;
    }

    int* arr = new int[c];

    int len = c;

    copy = number;

    while (number)
    {
        arr[--c] = number%10;
        number/=10;
    }
    for (int i=0; i<1 + len/2; i++)
    {
        if (arr[len-1-i]!=arr[i])
        {
            delete[] arr;
            return false;
        }
    }

    delete[] arr;
    return true;
}

int main()
{
    int m = 0;
	for (int a=999; a>99; a--)
    {
        for (int b=999; b>99; b--)
        {
            int x = a*b;
            if (is_palindrome(x))
            {
                if (x>m)
                    m = x;
            }

        }
    }
    cout << m << endl;
}
