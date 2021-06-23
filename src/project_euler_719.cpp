#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/// @brief Returns vector of digits of the number.
/// @return std::vector<char>
vector<char> digitsOfANumber(unsigned long long number)
{
    vector<char> res;
    do
    {
        res.insert(res.begin(), number % 10);
        number = number / 10;
    } while (number > 0);
    return res;
}

/// @brief Checks if sum of splilt is equal to target
/// @param digits Collection of digits in a number.
/// @param target The number we want to achieve.
/// @param sum Current sum passed into recursive calls.
/// @returns true if there exists a split summing to target, false otherwise.
bool generateSplits(const vector<char>& digits, const int target, int sum)
{
    if (digits.size() == 0)
    {
        return sum == target;
    }
    else if (digits.size() == 1)
    {
        return (sum + digits[0]) == target;
    }
    else if (sum == 0)
    {
        for (int i=0; i<digits.size()-1; i++)
        {
            int c = 0;
            for (int j=0; j<i+1; j++)
                c = 10*c + digits[j];
            if (sum+c > target)
                break;
            vector<char> newDigits(digits.begin()+i+1, digits.end());
            if (generateSplits(newDigits, target, sum + c))
                return true;
        }
    }
    else
    {
        for (int i=0; i<digits.size(); i++)
        {
            int c = 0;
            for (int j=0; j<i+1; j++)
                c = 10*c + digits[j];
            if (sum+c > target)
                break;
            vector<char> newDigits(digits.begin()+i+1, digits.end());
            if (generateSplits(newDigits, target, sum + c))
                return true;
        }
    }
    return false;
}

/// @brief Checks if square of a number is a S-Number.
bool isSNumber(int number)
{
    const long long target = (long long)number * number;
    vector<char> digits = digitsOfANumber(target);
    return generateSplits(digits, number, 0);
}

int main()
{
    unsigned long long sum = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        if (isSNumber(i))
        {
            sum+= 1ULL * i*i;
        }
    }
    cout << sum << endl;
}
