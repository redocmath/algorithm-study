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
#define MOD 1000007

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int w, h, x, y;

int dp[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> w>> h >> x >> y;
    dp[1][1] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++) {
            if (i > 1)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 1)
                dp[i][j] =(dp[i][j] + dp[i][j-1]) % MOD;
        }

    int tmp = dp[x][y];
    memset(dp, 0, sizeof(dp));
    dp[x][y] = 1;
    for (int i = x; i <= w; i++)
        for (int j = y; j <= h; j++) {
            if (i > 1)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 1)
                dp[i][j] =(dp[i][j] + dp[i][j-1]) % MOD;
        }
    ll ret = tmp * dp[w][h];
    cout << ret % MOD;
}