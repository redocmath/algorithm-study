#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 100000
using namespace std;

int n; 
int arr[MAX];
int dp[MAX] = {0, }; // cache[begin][end]

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = arr[0];
    int ans = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
