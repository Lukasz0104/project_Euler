#include <iostream>
#include <vector>

using namespace std;

bool is_abundant(int n)
{
    int s = 1;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            s = s + i;
            if (n/i != i)
                s += n/i;
        }
    }
    return s>n;
}

int main()
{
	vector<int> v;

    for (int i=1; i<=28123; i++)
    {
        if (is_abundant(i))
            v.push_back(i);
    }

    int s = 0;

    for (int i=1; i<=28123; i++)
    {
        bool f = false;
        for (int a=0; v[a]<i; a++)
        {
            for (int b=0; v[b]<=i-v[a]; b++)
            {
                if (v[a] + v[b] == i)
                {    
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        if (f == false)
        {
            s+=i;
        }
    }
    cout << s << endl;
}