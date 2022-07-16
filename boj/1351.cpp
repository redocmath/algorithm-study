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
#include <map>

using namespace std;
typedef long long ll;

int p, q;
map<ll, ll> dp;

ll solve(ll n) {
    if (dp.count(n)) return dp[n];
    dp[n] = solve(floor(n/p))+ solve(floor(n/q));
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n >> p >> q;
    dp[0] = 1;
    cout << solve(n);
}