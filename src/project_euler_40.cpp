#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int S = 1000001;
	char* N = new char[S];

    int num = 1;
    int r = 1;

    for (int i=0; i<S; i++)
    {
        N[i]='\0';
    }

    int i=1;
    while (strlen(N)<1000000)
    {
        static char a[7];
        sprintf(a,"%d",i);
        strcat(N, a);
        i++;
    }

    i = 1;

    for (int j=0; j<7; j++)
    {
        r *= int(N[i - 1])-48;
        i = 10*i;
    }

    cout << r << endl;
    delete[] N;
}
