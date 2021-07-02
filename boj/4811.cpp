#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;

ll dp[61][31][31];

ll solve(int l, int half, int one) {
    ll& tmp = dp[l][half][one];
    if (l == 2*n) return 1;
    if (tmp != -1) return tmp;

    if (half == 0) return tmp = solve(l+1, half+1, one-1);
    if (one == 0) return tmp = solve(l+1, half-1, one);
    return tmp = solve(l+1, half+1, one-1) + solve(l+1, half-1, one);
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << solve(0, 0, n) << "\n";
    }
    return 0;
}
