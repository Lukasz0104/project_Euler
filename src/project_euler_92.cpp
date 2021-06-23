#include <iostream>
#include <vector>

using namespace std;

vector<int> getDigitsList(unsigned int number)
{
    vector<int> d;
    while (number > 0)
    {
        d.insert(d.begin(), number%10);
        number/=10;
    }
    return d;
}

unsigned int sumSquaredDigits(const vector<int>& digits)
{
    unsigned int sum = 0;
    for (const auto& d : digits)
    {
        sum += d*d;
    }
    return sum;
}

int main()
{
    int count = 0;
    const int LIMIT = 10000000;
	for (int i=1; i<LIMIT; i++)
    {
        unsigned int x = i;
        do
        {
            x = sumSquaredDigits(getDigitsList(x));
        } while (x!=1 && x!=89);
        if (x==89)
        {
            count++;
        }
    }
    cout << count << endl;
}