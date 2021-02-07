#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 1500000
typedef long long ll;
using namespace std;

int t[MAX+1], p[MAX+1]; ll dp[MAX + 1];

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
        dp[i+1] = max(dp[i+1], dp[i]);
    }

    cout << dp[N + 1];
    
    return 0;
}
