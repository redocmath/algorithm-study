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

using namespace std;
typedef long long ll;

int dp[2001][2001];

int count(int last, int n) {
    if (dp[last][n] != -1) return dp[last][n];
    if (n == 0) return 1;
    int res = 0;
    for (int i = last+1; i <= n; i++) {
        res = (res + count(i, n-i) % 100999) % 100999;
    }
    dp[last][n] = res;
    return res;
}

int main() {
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++)
            dp[i][j] = -1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << count(0, n) << endl;
    }
}