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

int n, m;
vector<int> a;
vector<ll> segtree;

ll init(int nodel, int noder, int node) {
    if (nodel == noder) return segtree[node] = a[nodel];
    int mid = (nodel + noder) /2;
    return segtree[node] = max(init(nodel, mid, 2*node), init(mid+1, noder, 2*node+1));
}

ll query(int l, int r, int nodel, int noder, int node) {
    if (l > noder || r < nodel) return 0;
    if (l <= nodel && noder <= r) return segtree[node];
    int mid = (nodel+noder)/2;
    return segtree[node] = max(query(l, r, nodel, mid, 2*node), query(l, r, mid+1, noder, 2*node+1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    a.resize(n); segtree.resize(4*n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    init(0, n-1, 1);

    for (int i = m-1; i < n-m+1; i++) {
        cout << query(i-(m-1), i+(m-1), 0, n-1, 1) << " ";
    }
}
