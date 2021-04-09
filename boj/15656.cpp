#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
int a[7];

int cache[7];

void solve(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << cache[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cache[k] = a[i];
        solve(k+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    solve(0);
    return 0;
}
