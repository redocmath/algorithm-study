#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int m; cin >> m;
    while (m--) {
        int x; cin >> x;
        int st = 0, ed = n-1;

        bool isIn = false;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (a[mid] < x) {
                st = mid+1;
            } else if (a[mid] > x) {
                ed = mid-1;
            } else {
                isIn = true;
                break;
            }
        }

        if (isIn) cout << "1\n";
        else cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
