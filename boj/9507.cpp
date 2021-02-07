#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll dp[68];

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < 2; i++) dp[i] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) 
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];

        cout << dp[n] << endl;
    }
    return 0;
}
