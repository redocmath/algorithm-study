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

int n, m, K;
ll dp[101][101]; // (x, y)
bool iscon[201][201];

int main() {
    memset(iscon, 0, sizeof(iscon));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> K;
    while (K--) {
        int a, b, c, d; cin >> a>> b>>c>>d;
        iscon[a+c][b+d] = 1;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i >= 1) dp[i][j] += dp[i-1][j]*(1-iscon[2*i-1][2*j]);
            if (j >= 1) dp[i][j] += dp[i][j-1]*(1-iscon[2*i][2*j-1]);
        }
    }
    cout << dp[n][m];
}