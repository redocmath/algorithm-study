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

int n, coin[100];
int dp[10001];

int solve(int k) {
    int &res = dp[k];
    if (res != -1) return res;
    if (k == 0) return 0;

    res = 100000;
    for (int i = 0; i < n; i++) {
        if (k - coin[i] < 0) continue;
        res = min(res, solve(k-coin[i])+1);
    }
    
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    
    cout << (solve(k) == 100000 ? -1 : solve(k));
}