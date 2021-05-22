#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    int n; cin >> n;
    string s;
    cin>>s;
    int cnt_zero = 0;
    for (char e: s) {
        if (e == '0') cnt_zero++;
    }
    if (cnt_zero <= 2) cout << "BOB\n";
    else {

    }
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
