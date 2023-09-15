#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

bool bit(ll idx, ll k) {
    if (k == 1) return 2-idx;
    if (idx % 2)
        return 1-bit((idx-1)/2+1, k-1);
    else
        return bit((idx-1)/2+1, k-1);

    ll inverse = 0;
    while (k != 1) {
        if (idx % 2) 
            inverse++;
        idx = (idx-1)/2+1; k--;
    }
    
    if (inverse % 2) return 1-(2-idx);
    return 2-idx;
}

void device(ll k, ll l, ll r) {
    ll sum = max((r+1)/2 - (l+1)/2 - 1, 0ll);

    if (l == r) {
        cout << bit(l, k) << "\n";
        return;
    }
    if (r == l+1) {
        cout << bit(l, k) + bit(r, k) << "\n";
        return;
    }
    // l
    if (l % 2) sum++;
    else sum += bit(l, k);

    // r
    if (r % 2 == 0) sum++;
    else sum += bit(r, k);

    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // for (int i = 1; i <= 5; i++) {
    //     for (int j = 1; j <= pow(2, i); j++) cout << bit(j, i);
    //     cout << "\n";
    // }
    int t; cin >> t;
    while (t--) {
        ll k, l, r; cin >> k >> l >> r;
        device(k, l, r);
    }
}