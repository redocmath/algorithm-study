#include <bits/stdc++.h>
#define MOD 1000000007 
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, m, k;
vector<ll> a;
vector<ll> segtree;

ll construct(int l, int r, int node) {
    if (l == r) return segtree[node] = a[l];
    int mid = (l+r)/2;
    ll suml = construct(l, mid, 2*node);
    ll sumr = construct(mid+1, r, 2*node+1);
    return segtree[node] = (suml*sumr)%MOD;
}

ll querymul(int begin, int end, int node, int nodel, int noder) {
    if (end < nodel || noder < begin) return 1;
    if (begin <= nodel && noder <= end) return segtree[node];
    int mid = (nodel+noder)/2;
    return (querymul(begin, end, 2*node, nodel, mid)%MOD
        * querymul(begin, end, 2*node+1, mid+1, noder)%MOD);
}

ll queryupd(int index, ll newval, int node, int nodel, int noder) {
    if (index < nodel || index > noder) return segtree[node];
    if (nodel == noder) return segtree[node] = newval;
    int mid = (nodel+noder)/2;
    return segtree[node] = (queryupd(index, newval, node*2, nodel, mid)%MOD *
           queryupd(index, newval, node*2+1, mid+1, noder)%MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    a.resize(n);
    segtree.resize(4*n);

    for (int i = 0; i < n; i++) {cin >> a[i];}
    construct(0, n-1, 1);

   for (int i = 0; i < k+m; i++) {
        int a_, b_; ll c_; cin >> a_ >> b_ >> c_;
        b_--; c_--;
        if (a_ == 1) {
            queryupd(b_, c_+1, 1, 0, n-1);
            continue;
        } 
        cout << (querymul(b_, c_, 1, 0, n-1)) % MOD << "\n";
    }
    return 0;
}
