#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

bool solve() {
    int n; cin >> n;
    string s; cin >> s;

    bool used[26] = {0};
    char continuous = '1';
    for (char e: s) {
        if (used[e-'A']) return false;
        else if (continuous == '1') continuous = e;
        else if (continuous != e) {
            used[continuous-'A'] = 1;
            continuous = e;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
