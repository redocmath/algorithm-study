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
int n;
vector<int> coin;
ll dp[10001][101];

int solve(int k, int lcoin) {
    ll &res = dp[k][lcoin];
    if (res != -1) return res;
    if (k == 0) return 1;

    res = 0;
    for (int i = lcoin; i < n; i++) {
        if (k < coin[i]) continue;
        res += solve(k-coin[i], i);
    }
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k; cin >> n >> k;
    for (int i = 0; i < n; i++) { int tmp; cin >> tmp; coin.push_back(tmp); }

    sort(coin.begin(), coin.end());

    cout << solve(k, 0);
}