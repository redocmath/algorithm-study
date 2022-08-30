// 08:47
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

vector<int> square;
int dp[1000001][2];

int solve(int n, bool koosturn) {
    int &ret = dp[n][koosturn];
    if (ret != -1) return ret;
    if (n == 0) return ret = 1-koosturn;
    ret = 1-koosturn;
    for (int i = 0; i < square.size() && n - square[i] >= 0; i++) {
        if (solve(n-square[i], 1-koosturn) == koosturn) { ret = koosturn; break; }
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 1; i * i <= 1000000; i++) square.push_back(i*i);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (solve(n, 1) ? "koosaga" : "cubelover") << "\n";
    }
}