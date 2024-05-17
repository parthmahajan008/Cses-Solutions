#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    int missing = 0;
    for (int i = 1; i <= n; i++)
    {
        missing ^= i;
    }

    for (int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        missing ^= temp;
    }

    cout << missing << endl;

    return 0;
}