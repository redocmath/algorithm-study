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

int dp[10][1001];
int solve(int l, int n) {
    int &res = dp[l][n];
    if (res != -1) return res;
    if (n == 0) return 1;

    res = 0;
    for (int i = l; i < 10; i++)
        res = (res + solve(i, n-1) % 10007) % 10007;
    
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    cout << solve(0, n);
}