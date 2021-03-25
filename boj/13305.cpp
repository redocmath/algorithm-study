#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> d(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> d[i];
    }

    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    ll cnt = 0, tmp = 1234567891;
    for (int i = 0; i < n-1; i++) {
        if (cost[i] < tmp) tmp = cost[i];
        cnt += tmp * d[i];
    }
    cout << cnt;
    return 0;
}
