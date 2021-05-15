#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n, m;
vector<int> a;

void solve() {
    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int tmp = 0;
        for (int i = 0; i < n; i++) tmp += min(a[i], mid);
        if (tmp > m) hi = mid;
        else lo = mid;
    }
    int mx = -1;
    for (int i = 0; i < n; i++) mx = max(mx, min(a[i], lo));
    cout << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {int t; cin >> t; a.push_back(t);}
    cin >> m;
    solve();
    return 0;
}
