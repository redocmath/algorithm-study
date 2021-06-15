#include <bits/stdc++.h>
#include <numeric>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

bool cmp(P p1, P p2) {
    if (p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

int schedule[1000] = {0};

void solve() {
    int n; cin >> n;
    vector<P> a;
    for (int i = 0; i < n; i++) {
        int t1, t2; cin >> t1 >> t2;
        a.push_back({t1, t2});
    }
    sort(a.begin(), a.end(), cmp);
    for (P e: a) {
        for (int i = e.first-1; i >= 0; i--) {
            if (schedule[i]) continue;
            schedule[i] = e.second;
            break;
        }
    }
    cout << accumulate(schedule, schedule+1000, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
