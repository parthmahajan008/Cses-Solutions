// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
long long mod = (1e9 + 7);
int solveleetcode(int &k, int target, vector<int> &dp)
{
    if (target == 0)
        return 1;
    if (dp[target] != -1)
        return dp[target];
    int sum = 0;
    for (int i = 1; i <= min(k, target); i++)
    {
        sum = (sum + solveleetcode(k, target - i, dp)) % mod;
    }
    return dp[target] = sum;
}
int solve(int num, std ::vector<int> &dp)
{
    if (num < 0)
        return 0;
    if (num == 0)
        return 1;
    if (dp[num] != -1)
        return dp[num];
    long long one = solve(num - 1, dp);
    long long two = solve(num - 2, dp);
    long long three = solve(num - 3, dp);
    long long four = solve(num - 4, dp);
    long long five = solve(num - 5, dp);
    long long six = solve(num - 6, dp);
    return dp[num] = (one % mod + two % mod + three % mod + four % mod + five % mod + six % mod) % mod;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int k = 6;
    cout << solveleetcode(k, n, dp) << endl;
    return 0;
}