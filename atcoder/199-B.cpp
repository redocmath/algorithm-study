#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int mn = -1, mx = 2000;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        int tm = a[i], mp = b[i]; 
        mn = max(mn, tm);
        mx = min(mx, mp);
    }

    if (mn > mx) cout << "0";
    else cout << mx-mn+1;
    solve();
    return 0;
}
