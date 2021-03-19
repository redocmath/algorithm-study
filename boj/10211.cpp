// not solved yet
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int n;
int dp[1000];

int solve(vector<int>& a, int idx, bool connected) {
    int& tmp = dp[idx];
    if (tmp != -1) return tmp;
    if (idx == n - 1) return max(a[n - 1], 0);
    if (connected) {
        return tmp = max(0, a[idx] + solve(a, idx + 1, true));
    } else {
        return tmp = max(solve(a, idx + 1, false), a[idx] + solve(a, idx + 1, true));
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        cout << solve(x, 0, false) << endl;
        for (int i = 0; i < n; i++) cout << dp[i] << " ";
    } 
    return 0;
}
