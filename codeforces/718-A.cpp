#include <bits/stdc++.h>
#include <string>
typedef long long ll;
using namespace std;

void solve() {
    ll n; cin >> n;
    if (n % 2050) {
        cout << "-1\n"; return;
    }
    string s = to_string(n/2050);
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret += s[i]-'0';
    }
    cout << ret << "\n"; return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
