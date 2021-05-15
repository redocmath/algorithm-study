#include <bits/stdc++.h>
#pragma gcc optimize("o3")
#pragma gcc optimize("ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> p;

int n;
int a[25][25];
int dp[20][1<<21];

int solve(int k, int done) {
    int& ret = dp[k][done];
    if (ret != -1) return ret;
    if (done == (1 << n)-1) return 0;

    ret = 987654321;
    for (int i = 0; i < n; i++) {
        if (done & (1 << i)) continue;
        ret = min(ret, solve(k+1, done | (1 << i)) + a[k][i]);
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << solve(0, 0);
    return 0;
}
