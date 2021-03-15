#include <iostream>
#include <vector>

using namespace std;

int num_of_digits(long long n)
{
    int c = 0;
    do
    {
        c++;
        n/=10;
    } while (n);

    return c;
}

bool contains(const vector<long long> &v, long long number)
{
    for (int i=0; i<v.size(); i++)
    {
        if (v[i] == number)
            return true;
    }
    return false;
}

bool is_pandigital_product(int a, int b, vector<long long> &v)
{
    long long product = (long long)a * b;
    long long product_copy = product;

    if (9 != (num_of_digits(a) + num_of_digits(b) + num_of_digits(product)))
        return false;

    if (contains(v, product))
        return true;
    
    bool arr[9] = {false};//,false,false,false,false,false,false,false,false};
    while (a)
    {
        int k = a%10;
        arr[k-1] = true;
        a/=10;
    }
    while (b)
    {
        int k = b%10;
        arr[k-1] = true;
        b/=10;
    }
    while (product)
    {
        int k = product%10;
        if (k==0)
            return false;
        arr[k-1] = true;
        product/=10;
    }
    for (int i=0; i<9; i++)
    {
        if (arr[i] == false)
            return false;
    }
    v.push_back(product_copy);
    return true;
}

int main()
{
    vector<long long> v;
	for (int i=1; i<10000; i++)
    {
        for (int j=1; j<i && ((long long)i * j < 10000000000); j++)
        {
            is_pandigital_product(i,j,v);
        }
    }
    long long sum = 0;
    for (int i=0; i<v.size(); i++)
    {
        sum += v[i];
    }
    cout << sum << endl;
}