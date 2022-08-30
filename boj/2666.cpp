// 17:54
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

int n, a, b, len;
int plan[21];
int dp[21][21][21];

int solve(int p, int q, int k) {
    int &ret = dp[p][q][k];
    if (k == len) return 0;
    if (ret != -1) return ret;

    return ret = min(abs(plan[k]-q) + solve(p, plan[k], k+1), abs(plan[k]-p) + solve(plan[k], q, k+1));
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> a >> b >> len;
    for (int i = 0; i < len; i++) cin >> plan[i];
    cout << solve(a, b, 0);
}