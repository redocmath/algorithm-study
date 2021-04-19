#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    priority_queue<int> PQ;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 0) {
            if (PQ.empty()) cout << "0\n";
            else {
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        } else {
            PQ.push(x);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
