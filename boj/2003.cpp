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
    int ret = 0, s = 0, rs = 0, re = 0;
    while (true) {
        if (s >= m) s -= a[rs++];
        else if (re == n) break;
        else s += a[re++];
        if (s == m) ret++;
    }
    cout << ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {int a_; cin >> a_; a.push_back(a_);}
    solve();
    return 0;
}
