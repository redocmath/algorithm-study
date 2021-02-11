#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int dp[1516][1516] = {0};

int C(int n, int r) {
    int& tmp = dp[n][r];
    if (tmp != 0) return tmp;
    if (n == r || r == 0) return 1;
    return tmp = (C(n - 1, r - 1) + C(n - 1, r)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> availableK;

    for (int i = 0; i <= n-1; i++) {
        if ((4 * i + 4 + n) % 3 == 0) availableK.push_back(i);
    }

    int ret = 0;
    for (int i = 0; i < availableK.size(); i++) {
        ret = (ret + C(n - 1, availableK[i])) % MOD;
    }

    cout << ret;
    return 0;
}
