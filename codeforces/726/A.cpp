#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int solve() {
    int n; cin >> n;
    int ret =0;
    for (int i = 0; i < n; i++) {int t; cin >> t; ret += t;}
    
    if (ret == n) return 0;
    if (ret < n) return 1;
    return (ret - n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
