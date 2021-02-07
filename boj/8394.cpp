#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 10000000
typedef long long ll;
using namespace std;

int dp[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n+1; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    }

    cout << dp[n+1] << endl;
    return 0;
}
