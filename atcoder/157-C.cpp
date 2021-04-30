#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<int> a(n);
    fill(a.begin(), a.end(), -1);
    for (int i = 0; i < m; i++) {
        int s, c; cin >> s >> c;
        if (a[s-1] != -1 && a[s-1] != c) {
            cout << "-1"; return 0;
        }
        a[s-1] = c;
    }

    if (a.size() == 1) {
        cout << (a[0] == -1 ? 0 : a[0]);
    }
    else if (a[0] == 0) {
        cout << "-1";
    }
    else if (a[0] == -1) {
        cout << 1;
        for (int i = 1; i < 3; i++) cout << (a[i] == -1 ? 0 : a[i]);
    }
    else {
        for (int i = 0; i < 3; i++) cout << (a[i] == -1 ? 0 : a[i]);
    }

    return 0;
}
