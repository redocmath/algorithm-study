#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int solve() {
    int k; cin >> k;
    return 100 / (gcd(k, 100));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
