#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 80
using namespace std;

long long dp[MAX + 1];
int n;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << 4 * dp[n] + 2 * dp[n-1]; 

    return 0;
}
