#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b)
{
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b, a%b);
}

struct ProperFraction
{
    int numerator;
    int denominator;

    ProperFraction(int num, int den) : numerator(num / gcd(num,den)), denominator(den / gcd(num,den))
    {
    }
    bool operator<(const ProperFraction& x) const
    {
        return double(this->numerator)/double(this->denominator) < double(x.numerator)/double(x.denominator);
    }
    bool operator>(const ProperFraction &x) const
    {
        return x<(*this);
    }
    bool operator==(const ProperFraction& x) const
    {
        return this->numerator == x.numerator & this->denominator==x.denominator;
    }
    bool operator>=(const ProperFraction& x) const
    {
        return !((*this)<x);
    }
    friend ostream& operator<<(ostream& os, const ProperFraction& f)
    {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

int main()
{
	const int MAX_DENOMINATOR = 12000;

    set<ProperFraction> fractions;

    for (int d=2; d<=MAX_DENOMINATOR; d++)
    {
        for (int n= 1 + d/3; n < (d+1)/2; n++)
        {
            // ProperFraction f(n,d);
            // cout << f << endl;
            // fractions.insert(f);
            fractions.insert(ProperFraction(n,d));
        }
    }
    cout << fractions.size() << endl;
}