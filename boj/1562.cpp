#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;

int dp[100][1<<10][10];

int solve(int k, int used, int last) {
    if (k == n) {
        if (used == (1 << 10) - 1) return 1;
        return 0;
    }

    int& tmp = dp[k][used][last];
    if (tmp != -1) return tmp;

    if (k == 0) {
        int ret = 0;
        for (int i = 1; i <= 9; i++)
            ret = (ret + solve(k+1, used|(1 << i), i)) % (int)1e9;
        return tmp = ret;
    }
    if (last == 0) return tmp = solve(k+1, used|(1 << 1), 1) % (int)1e9;
    if (last == 9) return tmp = solve(k+1, used|(1 << 8), 8) % (int)1e9;
    return tmp = (
            solve(k+1, used|(1 << (last-1)), last-1)%(int)1e9
            + solve(k+1, used|(1 << (last+1)), last+1)%(int)1e9
    )%(int)1e9;
}

int main() {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < (1<<10); j++)
            fill(dp[i][j], dp[i][j]+10, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cout << solve(0, 0, 0);
    return 0;
}
