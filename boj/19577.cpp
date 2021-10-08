#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: idx = " << i << ", value = " << val << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;

int eulerPhi(int k) {
    int ret = k;
    for (int i = 2; i*i <= k; i++) {
        if (!(k % i)) {
            ret -= (ret / i);
            while (!(k % i)) k /= i;
        }
    }
    return k > 1 ? ret - (ret / k) : ret;
}

void solve() {
    V sol;
    for (int i = 1; i*i <= n; i++) {
        int cur = n / i;
        if (!(n % i) && cur * eulerPhi(cur) == n) sol.push_back(cur);
    }
    sort(sol.begin(), sol.end());
    if (sol.size()) cout << sol[0];
    else cout << "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;

    solve();
    return 0;
}
