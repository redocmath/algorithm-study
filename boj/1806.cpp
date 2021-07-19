#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, s;
vector<int> a;

void solve() {
    int sum = 0, lo = 0, hi = 0, mn = n+1;
    while (1) {
        if (sum >= s) {sum -= a[lo]; mn = min(mn, hi-lo); lo++;}
        else if (hi==n) break;
        else {sum += a[hi]; hi++;}
    }
    if (mn == n+1) cout << 0;
    else cout << mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;

    for (int i = 0; i < n; i++) {int t; cin >> t; a.push_back(t);}
    solve();
    return 0;
}
