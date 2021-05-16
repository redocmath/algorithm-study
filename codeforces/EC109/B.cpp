#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;


void solve() {
    int n; cin >> n;
    int a[50];
    for (int i = 0; i < n; i++) cin >> a[i];

    bool isgood = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != i+1) isgood = 0;
    }
    if(isgood) {cout << 0; return;}

    if (a[n-1] == n || a[0] == 1) {
        cout << 1; return;
    }
    if (a[n-1] == 1 && a[0] == n) {
        cout << 3; return;
    }
    cout << 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
