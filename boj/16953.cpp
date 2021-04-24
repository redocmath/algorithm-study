#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a, b;

void solve() {
    int tmp = b;
    int cnt = 1;
    bool bad = false;

    while (tmp > a) {
        if (tmp % 2) {
            if ((tmp - 1) % 10) {
                bad = true;
                break;
            }
            tmp = (tmp - 1) / 10;
        } else {
            tmp /= 2;
        }
        cnt++;
    }

    if (bad || tmp < a) cout << "-1";
    else cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;

    solve();
    return 0;
}
