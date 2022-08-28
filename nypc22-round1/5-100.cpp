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

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
vector<ll> a;
ll dp[1000001][2][2][2];

ll solve(ll idx, bool started, bool cutbeg, bool cutend) {
    ll& res = dp[idx][started][cutbeg][cutend];
    if (res != -1) return res;
    if (idx == n) return 0;

    if (cutend) // 지금까지 커트 끝 
        res = max(0ll, a[idx] + solve(idx+1, started, cutbeg, cutend));
    else if (cutbeg) // 다음부터 첫 커트 연속 시작
        res = max(solve(idx+1, started, cutbeg, 1), solve(idx+1, started, cutbeg, cutend));
    else if (started) // 지금부터 첫 연속 시작
        res = max(a[idx] + solve(idx+1, started, 1, cutend), a[idx] + solve(idx+1, started, cutbeg, cutend));
    else
        res = max(solve(idx, 1, cutbeg, cutend), solve(idx+1, started, cutbeg, cutend));
    
    // cout << idx << " " << started << " " << cutbeg << " " << cutend << ": " << res << "\n";
    return res;
}

int main() {
    memset(dp, -1ll, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << (solve(0, 0, 0, 0) == 0 ? *max_element(a.begin(), a.end()): solve(0,0,0,0));
}