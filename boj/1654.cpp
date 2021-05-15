#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

ll n, k;
vector<ll> a;

void solve() {
    ll lo = 0, hi = 2147483648-1;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll ret = 0;
        for (int i = 0; i < k; i++) ret += floor(a[i] / mid);
        if (ret >= n) lo = mid;
        else hi = mid;
    }
    cout << lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; i++) {ll t; cin >> t; a.push_back(t);}
    solve();
    return 0;
}
