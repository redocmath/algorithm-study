#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int a[3], b[2];
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int j = 0; j < 2; j++) cin >> b[j];

    int ret = 987654342;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            ret = min(ret, a[i]+b[j]);
    cout << ret-50;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
