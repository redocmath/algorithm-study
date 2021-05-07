#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

bool cmp(P p1, P p2) {
    return p1.second < p2.second;
}

void solve() {
    int n; cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp; a[i] = P(i, tmp);
    }

    int cnt = 0;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i].first > a[j].first
                    && a[i].second - a[j].second == a[i].first - a[j].first) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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
