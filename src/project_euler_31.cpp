#include <iostream>
#include <cstdio>

using namespace std;

int count_ways(int number, int a=0)
{
    if (number == 0 || a==7)
        return 1;
    int ways = 0;

    const int values[] = {200, 100, 50, 20, 10, 5, 2, 1};

    for (int i=0; i<=number/values[a]; i++)
    {
        ways += count_ways(number - values[a]*i, a+1);
    }

    return ways;
}

int count_ways_nested(int number)
{
    int ways = 0;
    for (int a=0; a<2; a++)
    {
        for (int b=0; b<=(number - 200*a)/100; b++)
        {
            for (int c=0; c<=(number - 200*a - 100*b)/50; c++)
            {
                for (int d=0; d<=(number-200*a - 100*b - 50*c)/20; d++)
                {
                    for (int e=0; e<=(number - 200*a - 100*b - 50*c - 20*d)/10; e++)
                    {
                        for (int f=0; f<=(number - 200*a - 100*b - 50*c - 20*d - 10*e)/5; f++)
                        {
                            for (int g=0; g<=(number - 200*a - 100*b - 50*c - 20*d - 10*e - 5*f)/2; g++)
                            {
                                ways++;
                                //printf("(%d,%d,%d,%d,%d,%d,%d,%d)\n",a,b,c,d,e,f,g,number-200*a-100*b-50*c-20*d-10*e-5*f-2*g);
                            }
                        }
                    }
                }
            }
        }
    }
    return ways;
}

int main()
{
    int number = 200;
    cout << count_ways(number) << endl;
}
