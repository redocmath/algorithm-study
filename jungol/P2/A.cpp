#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    int n, k, m; cin >> n >> k >> m;
    vector<int> space(m);
    for (int i = 0; i < m; i++) cin >> space[i];

    for (int i = 0; i < m; i++) {
        if (k <= space[i]) { cout << i+1 << "\n"; return;}
        else k -= space[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
