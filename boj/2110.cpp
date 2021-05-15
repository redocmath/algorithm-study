#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n, c;
vector<int> a;

void solve() {
    int lo = 0, hi = 1e9;
    while (lo+1<hi) {
        int mid = (lo+hi)/2;
        
        int ret = 1;
        int cur = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] - cur >= mid) {
                ret++;
                cur = a[i];
            }
        }

        if (ret >= c) lo = mid;
        else hi = mid;
    }
    cout << lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {int x; cin >> x; a.push_back(x);}
    sort(a.begin(), a.end());
    solve();
    return 0;
}
