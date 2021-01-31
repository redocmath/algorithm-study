#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 100000
using namespace std;

int dp[MAX + 1] = {0, };

int solve(int n) {
    int& tmp = dp[n];
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (tmp != 0) return tmp;

    if (solve(n - 2) == -1 && solve(n - 5) == -1)
        return tmp = -1;
    if (solve(n - 2) == -1)
        return tmp = 1 + solve(n - 5);
    if (solve(n - 5) == -1)
        return tmp = 1 + solve(n - 2);

    return tmp = 1 + min(solve(n - 2), solve(n - 5));
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cout << solve(n);
    return 0;
}
