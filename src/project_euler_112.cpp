#include <iostream>
#define ull unsigned long long

using namespace std;

bool is_decreasing(ull num)
{
    ull copy = num;
    int len = 0;
    while (copy)
    {
        len++;
        copy/=10;
    }

    int* arr = new int[len];

    int len_copy = len;

    while (num)
    {
        arr[--len_copy] = num%10;
        num/=10;
    }

    for (int i=1; i<len; i++)
    {
        if (arr[i]>arr[i-1])
            return false;
    }

    delete[] arr;
    return true;
}

bool is_increasing(ull num)
{
    ull copy = num;
    int len = 0;
    while (copy)
    {
        len++;
        copy/=10;
    }

    int* arr = new int[len];

    int len_copy = len;

    while (num)
    {
        arr[--len_copy] = num%10;
        num/=10;
    }

    for (int i=1; i<len; i++)
    {
        if (arr[i]<arr[i-1])
            return false;
    }

    delete[] arr;
    return true;
}

bool is_bouncy(ull num)
{
    return !is_increasing(num) && !is_decreasing(num);
}

int main()
{
    ull total = 99;
    ull count = 0;
    while (1.0 * count/total < 0.99)
    {
        total++;
        if (is_bouncy(total))
            count++;
    }
    cout << total << endl;
}
