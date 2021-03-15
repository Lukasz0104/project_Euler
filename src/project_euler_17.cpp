#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int sum_letters(int i, bool print = false)
{
    const char* digits[] = {"one","two","three","four","five","six","seven","eight","nine"};
    const char* less_than_20[] = {"ten", "eleven", "twelve", "thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    const char* tens[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    int num_of_letters = 0;

    if (i<10)
    {
        if (print)
            cout << digits[i-1] << " ";
        num_of_letters += strlen(digits[i-1]);
    }
    else if (i<20)
    {
        if (print)
            cout << less_than_20[i-10];
        num_of_letters += strlen(less_than_20[i-10]);
    }
    else if (i<100)
    {
        if (print)
            cout << tens[(i/10)%10 - 2] << " ";

        num_of_letters += strlen(tens[ (i/10)%10 - 2]);
        if (i%10 != 0)
        {
            if (print)
                cout << digits[i%10 - 1];
            num_of_letters += strlen(digits[i%10 - 1]);
        }
    }
    else if (i==1000)
    {
        if (print)
            cout << "one thousand";

        num_of_letters += strlen("one");
        num_of_letters += strlen("thousand");
    }
    else
    {
        if (print)
            cout << digits[i/100 - 1] << " hundred ";

        num_of_letters += strlen(digits[i/100 - 1]); //hundrets digit
        num_of_letters += strlen("hundred");

        if (i%100 != 0) //100*k
        {
            if (print)
                cout << "and ";

            num_of_letters += strlen("and");
            if (i%100 < 10 )
            {
                if (print)
                    cout << digits[i%100 - 1];

                num_of_letters += strlen(digits[i%100 - 1]);
            }
            else if (i%100 < 20)
            {
                if (print)
                    cout << less_than_20[i%100 - 10];

                num_of_letters += strlen(less_than_20[i%100 - 10]);
            }
            else
            {
                if (print)
                    cout << tens[(i/10)%10 - 2];

                num_of_letters += strlen(tens[(i/10)%10 - 2]);
                if (i%10 != 0)
                {
                    if (print)
                        cout << " " << digits[i%10 - 1];

                    num_of_letters += strlen(digits[i%10 - 1]);
                }
            }
        }        
    }

    if (print)
            cout << endl;
    
    return num_of_letters;
}

int main()
{
    bool print = false;
    int s = 0;
    for (int i=1; i<=1000; i++)
    {
        if (print)
            cout << setw(4) << i << ": ";
        s += sum_letters(i,print);
    }
    cout << s << endl;
    
    //cout << sum_letters(342) << endl;
    //cout << sum_letters(115) << endl;

}
