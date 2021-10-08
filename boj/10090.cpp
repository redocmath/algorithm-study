#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n; ll ret = 0;
vector<ll> segtree;

ll update(int node, int indx, int nodel, int noder) {
    if (indx < nodel || noder < indx) return segtree[node];
    if (nodel == noder) return segtree[node] = 1;
    int mid = (nodel+noder)/2;
    return segtree[node] = update(node*2, indx, nodel, mid) + update(node*2+1, indx, mid+1, noder);
}

ll query(int node, int l, int r, int nodel, int noder) {
    if (r < nodel || noder < l) return 0;
    if (l <= nodel && noder <= r) return segtree[node];
    int mid = (nodel+noder)/2; 
    return query(node*2, l, r, nodel, mid)+query(node*2+1, l, r, mid+1, noder);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    segtree.resize(4*n);
    
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ret += (ll)(a-1-query(1, 1, a-1, 1, n));
        update(1, a, 1, n);
    }
    cout << ret;
    return 0;
}
