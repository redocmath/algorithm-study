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

int n;
vector<int> A, B;
vector<ll> segtree;

void update(int idx, int nodel, int noder, int nodeidx) {
    if (idx > noder || idx < nodel) return;
    if (nodel <= idx && idx <= noder) segtree[nodeidx]++;
    if (nodel != noder) {
        int mid = (nodel+noder)/2;
        update(idx, nodel, mid, 2*nodeidx);
        update(idx, mid+1, noder, 2*nodeidx+1);
    }
}

ll query(int l, int r, int nodel, int noder, int idx) {
    if (l > noder || r < nodel) return 0;
    if (l <= nodel && noder <= r) return segtree[idx];
    int mid = (nodel+noder)/2;
    return query(l,r,nodel,mid,2*idx)+query(l,r,mid+1,noder,2*idx+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    A.resize(n); B.resize(1000001); segtree.resize(4*n);
    for (int i = 0; i < n; i++) { cin >> A[i]; }
    for (int i = 0; i < n; i++) { int t; cin >> t; B[t] = i; }

    // inversion-counting
    ll res = 0;
    for (int i = 0; i < n; i++) { 
        res += query(B[A[i]], n-1, 0, n-1, 1);
        update(B[A[i]], 0, n-1, 1);
    }
    cout << res;
}