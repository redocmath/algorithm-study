#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
int a[8];

int cache[8];
bool vis[8];

void solve(int k, int last) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << cache[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && a[i] > last) {
            cache[k] = a[i];
            vis[i] = true;
            solve(k+1, a[i]);
            vis[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    solve(0, 0);
    return 0;
}
