#include <bits/stdc++.h>
#include <cmath>
#define MOD 1000000009
typedef long long ll;
using namespace std;

int n, s;
int w[20], q[20];
int dp[20][1000000];

int solrecur(int k, int s_) {
    int& tmp = dp[k][s_];
    if (tmp != -1) return tmp;

    if (k == n-1) {
        if (q[k]) return tmp = (int)floor((s_)/w[k]) % MOD;
        else return tmp = ((int)floor((s_)/w[k]) + 1) % MOD;
    }

    tmp = 0;
    if (q[k]) {
        for (int i = w[k]; i <= s_; i += w[k]) {
            tmp = (tmp + solrecur(k+1, s_-i)) % MOD;
        }
    } else {
        for (int i = 0; i <= s_; i += w[k]) {
            tmp = (tmp + solrecur(k+1, s_-i)) % MOD;
        }
    }
    return tmp;
}


int main() {
    for (int i = 0; i < 20; i++) fill(dp[i], dp[i]+1000000, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> w[i] >> q[i];

    cout << solrecur(0, s);
    return 0;
}
