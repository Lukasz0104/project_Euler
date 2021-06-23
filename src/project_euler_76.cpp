#include <iostream>

using namespace std;

/// @brief Calculates number of partitions using recursive function calls.
/// If we start the process, the function goes through numbers [2,number-1], then for each of those numbers calculates how many times it fits into the remaining sum.
/// Next it is calling itself, with unchanged target, the number we just used and the new sum.
/// If on the other, the sum was greater than 0, we would go through numbers [2, largest], calculate how many times it fits into the remaining sum and calls itself.
/// Since the smalles number we reach is 2, we initialize the ways variable with value of 1, because there is only one way to get the result with just 1s.
/// @param target the number we want to find the number of ways to write as a sum
/// @param largest initially set to 0, because on the first call, we iterate through numbers in [2, number-1]
/// @param currentSum initially set to 0
/// @return calculated number of partitions
unsigned int countWays(const int target, const int largest = 0, int currentSum = 0)
{
    if (currentSum == target) 
        return 1;
    if ((target - currentSum) == 1) // there is only one way to add 1
        return 1;
    if (largest == 2) // there is only one way to get the remaining sum with only 1s
        return 1;
    unsigned int ways = 1; // we start with 1, because there is always one way to sum 1+1+1+...+1 (target times)

    if (currentSum == 0)
    {
        for (int i = target - 1; i > 1; i--)
        {
            for (int j = (target - currentSum)/i; j>0; j--)
            {
                ways += countWays(target, i, currentSum + i*j);
            }
        }
    }
    else
    {
        for (int i=largest - 1; i>1; i--)
        {
            for (int j=(target-currentSum)/i; j>0; j--)
            {
                ways+=countWays(target, i, currentSum + i*j);
            }
        }
    }    
    return ways;
}

int main()
{
	cout << countWays(100) << endl;
}