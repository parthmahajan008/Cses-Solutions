#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    long long n;
    cin >> n;
    unordered_map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        mp[temp]++;
    }
    cout << mp.size() << endl;
    return 0;
}