#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> ans(n);
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    long long moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (ans[i] < ans[i - 1])
        {
            moves += (ans[i - 1] - ans[i]);
            ans[i] = ans[i - 1];
        }
    }
    cout << moves << endl;
    return 0;
}