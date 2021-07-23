#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
V d;
V segtree;

int construct(int node, int l, int r) {
    if (l == r) return segtree[node] = d[l];
    int mid = (l + r) / 2;
    int minl = construct(node*2, l, mid);
    int minr = construct(node*2+1, mid+1, r);
    return segtree[node] = min(minl, minr);
}

int query(int node, int l, int r, int nodel, int noder) {
    if (r < nodel || noder < l) return INT_MAX;
    if (l <= nodel && noder <= r) return segtree[node];
    int mid = (nodel + noder) / 2;
    return min(query(node*2, l, r, nodel, mid)
            , query(node*2+1, l, r, mid+1, noder));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int m; cin >> m;
    d.resize(n);
    segtree.resize(4*n);

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    construct(1, 0, n-1);

    while (m--) {
        int a, b; cin >> a >> b; a--; b--;
        cout << query(1, a, b, 0, n-1) << "\n";
    }
    return 0;
}
