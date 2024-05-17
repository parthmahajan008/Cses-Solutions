
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
long long mod = (1e9 + 7);
long long dp[101][1000001];
// write the function for the dp Consider a money system consisting of n
//   coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x
//   using the available coins.

// For example, if the coins are {2,3,5}
//  and the desired sum is 9
// , there are 3
//  ways:
int solve(vector<int> &coins, int ind, int x)
{
    if (ind == 0)
    {
        if (x % coins[ind] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][x] != -1)
        return dp[ind][x] % mod;
    int take = 0;
    if (coins[ind] <= x)
        take += solve(coins, ind, x - coins[ind]);
    int notTake = solve(coins, ind - 1, x);
    return dp[ind][x] = (take + notTake) % mod;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<long long> prev(amount + 1, 1);
    for (int target = 0; target <= amount; target++)
        prev[target] = (int)target % coins[0] == 0;

    for (int i = 1; i < n; i++)
    {
        vector<long long> curr(amount + 1, 0);
        for (int j = 1; j <= amount; j++)
        {
            int doNotTake = prev[j] % mod;
            int take = 0;
            if (j >= coins[i])
                take = curr[j - coins[i]];
            curr[j] = (take + doNotTake) % mod;
        }
        prev = curr;
    }
    cout << (int)(prev[amount] % mod);
    return 0;
}
int main()
{

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    change(x, coins);
    cout << endl;
    return 0;
}