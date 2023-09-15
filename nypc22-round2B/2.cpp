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
#include <deque>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll dp[90001];

ll solve(ll a, ll b) {
    cout << a << " " << b << "\n";
    if (a == 0) return 987654321;
    ll &ret = dp[a];
    if (a == b) return 0;
    if (a > b) return a-b;
    if (ret != -1) return ret;
    return ret = 1+min({solve(a-1, b), solve(a+1, b), solve(a*a, b)});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        memset(dp, -1, sizeof(dp));
        ll a, b; cin >> a >> b;
        if (b > a) cout << solve(a, b) << "\n";
        else cout << solve(b, a) << "\n";
    }
}