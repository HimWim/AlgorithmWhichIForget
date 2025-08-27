#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);

    if (a == 0)
    {
        // Every number divide 0
        return b;
    }
    else if (a == b)
    {
        // Equal numbers have same gcd
        return a;
    }

    return gcd(a, b % a);
    // gcd(a,b) = gcd(a,b-q*a) --> Imp
}

int main()
{
    int a = 15;
    int b = 25;

    if (a >= b)
    {
        swap(a, b);
    }
    cout << gcd(a, b);
}