#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
int a[8];
int cache[8];

void solve(int k, int last) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << cache[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (last > a[i]) continue;
        cache[k] = a[i];
        solve(k+1, a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    solve(0, 1);
    return 0;
}
