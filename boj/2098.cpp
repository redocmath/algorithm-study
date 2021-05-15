#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
int w[16][16];
int dp[16][1<<16];

int solve(int k, int visited) {
    int& ret = dp[k][visited];
    if (ret != -1) return ret;

    if (visited == (1 << n) - 1) {
        if (w[k][0]) return w[k][0];
        else return 987654321;
    }

    ret = 987654321;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i) || w[k][i] == 0) continue;
        ret = min(ret, solve(i, visited | (1 << i)) + w[k][i]);
    }
    return ret;
}

int main() {
    for (int i = 0; i < 16; i++) fill(dp[i], dp[i]+(1<<16), -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    cout << solve(0, 1);
    return 0;
}
