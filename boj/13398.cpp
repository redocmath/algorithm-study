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

int n;
int arr[100001];
int dp[100001][2][2];

int solve(int i, bool isused, bool isstarted) {
    if (i == n+1) return 0;
    int &ret = dp[i][isused][isstarted];
    if (ret != -1) return ret;
    
    if (isstarted) {
        ret = max({
            solve(i+1, isused, isstarted) + arr[i],
            0
        });
        if (!isused) ret = max(ret, solve(i+1, true, isstarted));
        return ret;
    }
    ret = max({
        solve(i+1, isused, isstarted),
        solve(i+1, isused, true) + arr[i],
        0
    });
    if (!isused) ret = max(ret, solve(i+1, true, isstarted));
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int res = solve(1, 0, 0);
    if (res == 0) res = *max_element(arr+1, arr+n+1);
    cout << res;
}