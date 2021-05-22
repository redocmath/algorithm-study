#include <algorithm>
#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    int n; cin >> n;
    vector<P> a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        a.push_back(P(t, i));
    }
    sort(a.begin(), a.end());
    for (P e: a) {
        cout << e.second <<" ";
    }

    for (int i = 0; i < n; i++) {
        auto e = upper_bound(a.begin(), a.end(), a[i]);
        for (int )
        i = e-a.begin() + 1;
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
