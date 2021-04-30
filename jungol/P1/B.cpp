#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int m, n, d; // ver hor size
int a[100][100]; // board

void solve() {
    int cnt = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (a[i][j]) continue;
            // case 1.
            if (j+d-1 >= n) continue;
            
            bool isGood = true;
            for (int k = j; k < j+d; k++) {
                if (a[i][k]) {
                    isGood = false;
                    break;
                }
            }
            if (isGood) cnt++;
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            // case 2.

            if (i+d-1 >= m) continue;

            bool isGood = true;
            for (int k = i; k < i+d; k++) {
                if (a[k][j]) {
                    isGood = false;
                    break;
                }
            }
            if (isGood) cnt++;
        }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> d;

    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '.') a[i][j] = 0;
            else if (s[j] == '#') a[i][j] = 1;
        }
    }
    solve();
    return 0;
}
