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

int n, q;
vector<ll> A;
vector<ll> segtree;

ll construct(int l, int r, int node) {
    if (l == r) return segtree[node] = A[l];
    int mid = (l+r)/2;
    ll suml = construct(l, mid, 2*node);
    ll sumr = construct(mid+1, r, 2*node+1);
    return segtree[node] = suml+sumr;
}

ll update(ll idx, ll diff, int nodel, int noder, int node) {
    if (idx < nodel || noder < idx) return segtree[node];
    if (nodel == noder) return segtree[node] = diff;
    int mid = (nodel+noder)/2;
    return segtree[node] = update(idx, diff, nodel, mid, node*2) + 
        update(idx, diff, mid+1, noder, 1+node*2);
}

ll query(int l, int r, int nodel, int noder, int node) {
    if (l > noder || r < nodel) return 0;
    if (l <= nodel && noder <= r) return segtree[node];
    int mid = (nodel+noder)/2;
    return query(l, r, nodel, mid, 2*node) + query(l, r, mid+1, noder, 2*node+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    A.resize(n+1);
    segtree.resize(4*n);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    construct(1, n, 1);
    while (q--) {
        ll x, y, a, b; cin >> x >> y >> a >> b;
        if (x > y) cout << query(y, x, 1, n, 1) << "\n";
        else cout << query(x, y, 1, n, 1) << "\n";
        update(a, b, 1, n, 1);
    }
}