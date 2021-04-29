#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    double r, b, d; cin >> r >> b >> d;
    if (r > b) {
        if (r / b - 1 <= d) cout << "YES";
        else cout << "NO";
    }
    else {
        if (b / r - 1 <= d) cout << "YES";
        else cout << "NO";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
