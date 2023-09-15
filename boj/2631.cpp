// 06:54
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

int n;
int a[201];
int dp[201][201];

// LIS
int solve(int x, int mx) {
    int &ret = dp[x][mx];
    if (x == n) return 0;
    if (ret != -1) return ret;

    if (a[x] > mx)
        return ret = max(solve(x+1, mx), 1+solve(x+1, a[x]));
    else
        return ret = solve(x+1, mx);
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << n-solve(0, 0);
}