#include <algorithm>
#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
ll basic_number, alt_count, res = 0;
vector<ll> m;

void solve() {
    const int c = upper_bound(m.begin(), m.end(), basic_number)-m.begin();
    for (int i = n-1; i >= c; i--) {
        if (n-i-1 < alt_count) res += m[i]-basic_number-1;
        else res += m[i]-basic_number;
    }
}

int main() {
    scanf("%d", &n);
    m.resize(n);

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll e;
        scanf("%lld", &e);
        m[i] = e;
        sum += e;
    }

    sort(m.begin(), m.end());

    basic_number = sum / n;
    alt_count = sum % n;
    solve();
    printf("%lld", res);
    return 0;
}
