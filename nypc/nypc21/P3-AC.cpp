#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, k;
vector<P> a;
vector<int> mx;
vector<V> res;

void solve() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < mx[i]; j++) {
            if (a[j].first == 0) break;
            a[j].first--;
            res[i].push_back(a[j].second);
        }
        sort(a.begin(), a.end(), greater<P>());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    mx.resize(k); res.resize(k);
    for (int i = 1; i <= n; i++) {
        int e; cin >> e;
        a.push_back({e, i});
    }
    sort(a.begin(), a.end(), greater<P>());
    for (int i = 0; i < k; i++) {
        cin >> mx[i];
    }
    solve();
    for (int i = 0; i < k; i++) {
        cout << res[i].size() << " ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
