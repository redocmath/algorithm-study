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

int rec[1001];
int dp[1001][31][3];

int T, W;

int solve(int t, int w, int below) {
    int &ret = dp[t][w][below];
    if (ret != -1) return ret;
    if (t == T+1) return 0;

    ret = max(
        solve(t+1, w, below) + (rec[t] == below),
        (w == 0 ? -1 : solve(t+1, w-1, (below == 1 ? 2 : 1)) + (rec[t] == (below == 1 ? 2 : 1)))
    );
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T >> W;
    for (int i = 1; i <= T; i++)
        cin >> rec[i];
    
    cout << solve(1, W, 1);
}