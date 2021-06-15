#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
int a[100];
ll dp[101][21];

ll solve(int idx, int ret) {
    ll& tmp = dp[idx][ret];
    if (tmp != -1) return tmp;
    if (idx == n-1) {
        if (ret == a[n-1]) return 1;
        else return 0;
    }

    return tmp = (ret+a[idx] <= 20 ? solve(idx+1, ret+a[idx]): 0) + (ret-a[idx] >= 0 ? solve(idx+1, ret-a[idx]) : 0);
}

int main() {
    for (int i = 0; i < 101; i++) fill(dp[i], dp[i]+21, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(1, a[0]);
    return 0;
}
