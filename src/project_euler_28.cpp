#include <iostream>
#include <iomanip>

#define LEN 1001

using namespace std;

int main()
{
    static int P[LEN][LEN];

    //filling
    int a = 4;
    int x = (LEN-1)/2;
    int y = (LEN-1)/2;

    P[x][y] = 1;
    y++;
    P[x][y] = 2;
    x++;
    P[x][y] = 3;
    //y--;

    int phase = 0;
    int k = 0;
    int d = 2;

    while (a <= LEN*LEN)
    {
        switch (phase)
        {
            case 0:
                y--;
                break;
            case 1:
                x--;
                break;
            case 2:
                y++;
                break;
            case 3:
                x++;
                break;
        }
        P[x][y] = a;
        k++;

        if (k==d)
        {
            phase = (phase+1)%4;
            if (phase%2==0)
                d++;
            k=0;
        }
        if (0)
        {
            for (int i=0; i<LEN; i++)
            {
                for (int j=0; j<LEN; j++)
                {
                    cout << setw(3) << P[i][j] << " ";
                }
                cout << endl;
            }
            cout << "====================\n";
        }
        a++;
    }
    
    if (0)
    {
        for (int i=0; i<LEN; i++)
        {
            for (int j=0; j<LEN; j++)
            {
                cout << setw(7) << P[i][j] << " ";
            }
            cout << endl;
        }
    }

    unsigned long long sum = 0;
    for (int i=0; i<LEN; i++)
    {
        //cout << P[i][i] << " + " << P[LEN-1-i][i] << endl;
        sum += P[i][i];
        sum += P[LEN-1-i][i];
    }
    sum--;
    cout << sum << endl;
}