#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    ll n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        if (n % 200) {
            n *= 1000;
            n += 200;
        }
        else {
            n /= 200;
        }
    }
    cout << n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
