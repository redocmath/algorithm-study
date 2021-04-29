#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n, m, k;

int dx[] = {1, 0};
int dy[] = {0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if (n-1 + n * (m - 1) == k) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
