// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
const int maxX = 1e6;
const int INF = 0x3f3f3f3f;
int solve(int ind, int target, vector<int> &coins)
{
    if (ind < 0 && target != 0)
        return INF;
    if (target == 0)
        return 0;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int take = INF;
    if (coins[ind] <= target)
    {
        take = 1 + solve(ind, target - coins[ind], coins);
    }
    int notTake = solve(ind - 1, target, coins);
    return dp[ind][target] = min(take, notTake);
}
void tabulation()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    dp.resize(n, vector<int>(x + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            int take = INF;
            if (coins[i] <= j)
                take = 1 + dp[i][j - coins[i]];
            int notTake = INF;
            if (i > 0)
                notTake = dp[i - 1][j];
            dp[i][j] = min(take, notTake);
        }
    }
    if (dp[n - 1][x] == INF)
        cout << -1 << endl;
    else
        cout << dp[n - 1][x] << endl;
}
int main()
{
    tabulation();
    // int n, x;
    // cin >> n >> x;
    // vector<int> coins(n);
    // for (int i = 0; i < n; i++)
    //     cin >> coins[i];
    // dp.resize(n, vector<int>(x + 1, -1));
    // int ans = solve(n - 1, x, coins);
    // if (ans == INF)
    //     cout << -1 << endl;
    // else
    //     cout << ans << endl;
    return 0;
}