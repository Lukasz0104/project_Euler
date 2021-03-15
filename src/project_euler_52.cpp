#include <iostream>

using namespace std;

int num_of_digits(unsigned int n)
{
    int c = 0;
    do
    {
        c++;
        n/=10;
    } while (n);

    return c;
}

bool is_permutation(unsigned int x, unsigned int y)
{
    const int sx = num_of_digits(x);
    const int sy = num_of_digits(y);

    if (sx != sy)
        return false;

    int digits_x[sx];
    int digits_y[sy];

    int i = sx - 1;

    while (x)
    {
        digits_x[i] = x%10;
        x/=10;
        i--;
    }

    i = sy - 1;
    while (y)
    {
        digits_y[i] = y%10;
        y/=10;
        i--;
    }

    for (int i=0; i<sx; i++)
    {
        bool is_p = false;
        for (int j=0; j<sy; j++)
        {
            if (digits_y[j] == digits_x[i])
            {
                is_p = true;
                break;
            }
        }
        if (false == is_p)
            return false;
    }

    for (int i=0; i<sy; i++)
    {
        bool is_p = false;
        for (int j=0; j<sx; j++)
        {
            if (digits_y[i] == digits_x[j])
            {
                is_p = true;
                break;
            }
        }
        if (false == is_p)
            return false;
    }

    return true;
}

int main()
{
	unsigned int i = 1;
    while (!is_permutation(i, 2*i) || !is_permutation(i, 3*i) || !is_permutation(i, 3*i) || !is_permutation(i, 4*i) || !is_permutation(i, 5*i) || !is_permutation(i, 6*i))
    {
        i++;
    }
    cout << i << endl;
}