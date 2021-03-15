#include <iostream>

using namespace std;

int main()
{
    int num = 1, den = 1;
	for (int A = 1; A<10; A++)
    {
        for (int B=1; B<10; B++)
        {
            for (int C=1; C<10; C++)
            {
                if (A==B && B==C)
                    continue;
                if (1.0*(10*A + B)/(10*A + C) == 1.0 * B/C && C>B) //ab/ac == b/c
                {
                    //cout << 10*A + B << "/" << 10*A + C << endl;
                    num *= (10*A + B);
                    den *= (10*A + C);
                }
                else if (1.0 * (10*A+B)/(10*B+C) == 1.0 * A/C && C>A) //ab/bc == ac
                {
                    //cout << 10*A + B << "/" << 10*B + C << endl;
                    num *= (10*A + B);
                    den *= (10*B + C);
                }
                else if (1.0 * (10*A + B)/(10*C+A) == 1.0 * B/C && C>B) //ab/ca == bc
                {
                    //cout << 10*A + B << "/" << 10*C + A << endl;
                    num *= (10*A + B);
                    den *= (10*C + A);
                }
                else if (1.0 * (10*A+B)/(10*C+B) == 1.0*A/C && C>A) //ab/cb == ac
                {
                    //cout << 10*A + B << "/" << 10*C + B << endl;
                    num *= (10*A + B);
                    den *= (10*C + B);
                }
            }
        }
    }
    int i=2;
    while (i<=num)
    {
        while (num%i==0 && den%i==0)
        {
            num/=i;
            den/=i;
        }
        i++;
    }
    cout << den << endl;
}
