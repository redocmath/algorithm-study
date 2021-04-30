#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[3][3];
bool b[3][3];

void solve() {
    
}

int main() {
    for (int i = 0; i < 3; i++) fill(b[i], b[i]+3, 0);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> a[i][j];

    int n; cin >> n;
    while(n--) {
        int k; cin >> k;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == k) b[i][j] = 1;
            }
    }

    bool is = false;
    if (b[0][0] && b[1][1] && b[2][2]) is = true;
    else if (b[0][2] && b[1][1] && b[2][0]) is = true;
    else {
        for (int i = 0; i < 3; i++) {
            if (b[i][0] && b[i][1] && b[i][2]) is = true;
        }
        for (int i = 0; i < 3; i++) {
            if (b[0][i] && b[1][i] && b[2][i]) is = true;
        }
    }

    cout << (is ? "Yes" : "No");
    return 0;
}
