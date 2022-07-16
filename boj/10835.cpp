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

int N;
int L[2000], R[2000];
int dp[2001][2001];

int solve(int l, int r) {
    int &ret = dp[l][r];
    if (ret != -1) return ret;
    if (l == N || r == N) return 0;

    ret = max({
        solve(l+1, r),
        solve(l+1, r+1),
    });

    if (L[l] > R[r]) ret = max(ret, solve(l, r+1)+R[r]);
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> L[i];
    
    for (int i = 0; i < N; i++)
        cin >> R[i];
    
    cout << solve(0, 0);
}