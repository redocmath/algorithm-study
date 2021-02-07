#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll dp[100001];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j*j<=i; j++)
            dp[i] = min(dp[i], dp[i - j*j] + 1);
    }

    cout << dp[n];
    return 0;
}
