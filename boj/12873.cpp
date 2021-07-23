#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, q;
vector<ll> segtree;

ll update(int node, int indx, int newval, int nodel, int noder) {
    if (indx < nodel || noder < indx) return segtree[node];
    if (nodel == noder) return segtree[node] += newval;
    int mid = (nodel+noder)/2;
    return segtree[node] = update(node*2, indx, newval, nodel, mid) +
        update(node*2+1, indx, newval, mid+1, noder);
}

ll sum(int node, int l, int r, int nodel, int noder) {
    if (r < nodel || noder < l) return 0;
    if (l <= nodel && noder <= r) return segtree[node];
    int mid = (nodel + noder) / 2;
    ll suml = sum(node*2, l, r, nodel, mid);
    ll sumr = sum(node*2+1, l, r, mid+1, noder);
    return suml+sumr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    segtree.resize(4*n);
    fill(segtree.begin(), segtree.end(), 0);
    
    while (q--) {
        int A, B, C; cin >> A >> B >> C;
        B--;

        if (A == 1) {
            update(1, B, C, 0, n-1);
            continue;
        }
        C--;
        cout << sum(1, B, C, 0, n-1) << "\n";
    }
    return 0;
}
