#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int coin[20], n; 
ll dp[10001][20];

int solve(int m, int lcoin) {
    ll &ret = dp[m][lcoin];
    if (ret != -1) return ret;
    if (m == 0) return 1;

    ret = 0;
    for (int i = lcoin; i < n; i++) {
        if (m - coin[i] < 0) continue;
        ret += solve(m-coin[i], i);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        
        int m; cin >> m;
        cout << solve(m, 0) << "\n";
    }
}