#include <iostream>
#include <set>

#define UPPER 1000000

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
};

ostream& operator<<(ostream& os, const ProperFraction& f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& s)
{
    os << "{";
    if (s.size() > 0)
    {
        os << *(s.begin());
        for (const T& x : s)
        {
            if (*(s.cbegin()) == x) continue;
            os << ", " << x;
        }
    }
    os << "}";
    return os;
}

int main()
{
	

    const ProperFraction f(3,7);

    ProperFraction previous(1,UPPER);

    for (int d=1; d<=UPPER; d++)
    {
        /*
        The init statement for the nested loops comes from the following reasoning:
        let S = x/y be the fraction closest to 3/7
        We don't want to check every fraction with numerator starting from 1.
        Let X = n/d, where d is fixed in outer loop, be such a fraction, that X>S.
        Therefore we can write the following:
            x/y < n/d
        Multiplying both sides by d we get:
            x * d / y < n
        Hence the value for n in the nested loop.
        Also we need to convert the numerator to long long as there were runtime errors otherwise.
        Theoretically we could do the same for the terminating condition, but it was easier to check inside the loop, if the value is over 3/7.
        */
        for (int n = (long long)d * previous.numerator / previous.denominator; n<d; n++)
        {
            ProperFraction x(n,d);
            if (x >= f) break;
            if (x > previous)
                previous = x;
        }
    }

    cout << previous << endl;
    
    return 0;
}
