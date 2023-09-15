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
#include <deque>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, m;
int a[101];
int dp[101][101][2];

int solve(int idx, int inter, bool ison) {
    int &ret = dp[idx][inter][ison];
    if (inter == m) return ret = 0;
    if (idx >= n) return ret = -1000000000;
    if (ret != -1) return ret;
    if (ison) return ret = max(a[idx]+solve(idx+1, inter, ison), a[idx]+solve(idx+2, inter+1, 0));
    return ret = max(solve(idx+1, inter, ison), solve(idx, inter, 1));
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, 0, 0);
}