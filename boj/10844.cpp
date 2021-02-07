#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MOD 1000000000
typedef long long ll;
using namespace std;

int dp[101][10];

int getCount(int length, int prvNum) {
    int& tmp = dp[length][prvNum];
    if (tmp != -1) return tmp;
    if (length == 1)
        return tmp = 1;
    if (prvNum == 0) 
        return tmp = getCount(length - 1, 1) % MOD;
    if (prvNum == 9)
        return tmp = getCount(length - 1, 8) % MOD;
    return tmp = (getCount(length - 1, prvNum-1) + getCount(length - 1, prvNum+1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < 101; i++) {
        memset(dp[i], -1, sizeof(int) * 10);
    }
    
    ll ans = 0;
    for (int i = 1; i <= 9; i++)
        ans = (ans + getCount(n, i)) % MOD;

    cout << ans;
    return 0;
}
