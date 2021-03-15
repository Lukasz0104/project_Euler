#include <iostream>
#define UPPER 1000000

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

bool is_palindrome_base2(int number)
{
    int len = 0;
    int copy = number;
    while (copy)
    {
        len++;
        copy/=2;
    }

    int *arr = new int[len];

    for (int i=0; i<len; i++)
    {
        arr[i] = number & 1;
        number>>=1;
    }

    for (int i=0; i<len; i++)
    {
        if (arr[i] != arr[len-i-1])
            return false;
    }

    delete[] arr;
    return true;
}

int main()
{
    unsigned int sum = 0;
    for (int i=0; i<UPPER+1; i++)
    {
        if (is_palindrome(i) && is_palindrome_base2(i))
            sum += i;
    }
    cout << sum << endl;
}
