#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 50000
using namespace std;

int n; int dp[MAX + 1] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int& ret = dp[i];
        ret = (double)round(sqrt(i)) == sqrt(i) ? 1 : 50000;
        for (int j = 1; j < int(sqrt(i)); j++) {
            ret = min(ret, dp[j*j] + dp[i - j*j]);
        }
    }

    cout << dp[n];
    return 0;
}
