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
int res = 0;
vector<int> a;
vector<P> modifi;

void solve() {
    for (int i = 0; i < n; i++) {
        vector<int> C(a.begin()+modifi[2*i].second+1, a.begin()+modifi[2*i+1].second); sort(C.begin(), C.end());
        int cnt = modifi[2*i+1].second-modifi[2*i].second-1;
        if (C.size() == 0) continue;
        for (int j = 0; j < C.size()-1; j++) {
            if (C[j] == C[j+1]) cnt -= 2;
        }
        res += cnt;
    }
    cout << res / 2 + n + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(2*n);
    modifi.resize(2*n);

    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
        modifi[i] = {a[i], i};
    }

    sort(modifi.begin(), modifi.end());

    solve();
    return 0;
}
