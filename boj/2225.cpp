#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
const int MOD = 1e9;

int dp[201][201];
int N, K;

int solve(int n, int k) {
    int& tmp = dp[n][k];
    if (k == 0) {
        return (n == 0 ? 1 : 0);
    }
    if (tmp != -1) return tmp;
    int ret = 0;
    for (int i = 0; i <= n; i++) ret = (ret + solve(n-i, k-1)) % MOD;
    return tmp = ret;
}

int main() {
    for (int i = 0; i < 201; i++) fill(dp[i], dp[i]+201, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    cout << solve(N, K);
    return 0;
}
