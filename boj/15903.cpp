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

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll n, m;
vector<ll> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    
    while (m--) {
        sort(a.begin(), a.end());
        ll res = a[0] + a[1];
        a[0] = res; a[1] = res;
    }

    ll res = 0;
    while (n--) res += a[n];
    cout << res;
}