#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, m;
vector<int> a;

void solve() {
    int lo = 0, hi = 1, ans = 1234567890;
    while (hi < n) {
        if (a[hi]-a[lo] < m) hi++;
        else if (a[hi]-a[lo] == m) {ans = m; break;}
        ans = min(ans, a[hi]-a[lo]);
        lo++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t; cin >> t; a.push_back(t);
    }
    sort(a.begin(), a.end());
    solve();
    return 0;
}
