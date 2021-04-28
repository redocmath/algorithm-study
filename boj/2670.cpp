#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

double dp[2][10000];
double a[10000];
int n;

double solve(bool wasStarted, int k) {
    if (k == n) return 1;
    double& tmp = dp[wasStarted ? 1 : 0][k];
    if (tmp != -1) return tmp;

    if (wasStarted) return tmp = max(a[k] * solve(true, k+1), 1.0);
    return tmp = max(a[k] * solve(true, k+1), solve(false, k+1));
}

int main() {
    for (int i = 0; i < 2; i++) fill(dp[i], dp[i]+10000, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << fixed;
    cout.precision(3);
    cout << solve(false, 0);
    return 0;
}
