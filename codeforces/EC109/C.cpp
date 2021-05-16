#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
bool a[5000];

int solve(int k, int occupied) {
    if (k == n) return 0;
    if (!a[k]) return solve(k+1, occupied);
    else {
        int ret = 987654321;
        for (int i = 0; i < n; i++) {
            if (i == k || (occupied & (1 << i)) || a[i]) continue;
            int tmp = occupied;
            tmp |= (1 << i);
            tmp &= ~(1 << k);
            ret = min(
                ret,
                abs(k-i) + solve(
                    k+1,
                    tmp
                )
            );
        }
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int occupied = 0;
    for (int i = n-1; i >= 0; i--) {
        int t; cin >> t;
        if (t) {
            occupied |=(1 << i);
            a[(n-i-1)] = 1;
        } else {
            a[(n-i-1)] = 0;
        }
    }

    cout << solve(0, occupied);
    return 0;
}
