#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prime(101, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= 100; i++)
    // Used i*i because lets say we want to check for N -> 1*100, 2*50, 3*(100/3)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 100; j += i)
            {
                // Used i*i because before it everyone
                // everyone will be marked to 0 by other previous prime numbers
                // Why? -> think (prevPrime*i) will already be marked. So next unmarked composite number will be i*i
                prime[j] = 0;
            }
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}