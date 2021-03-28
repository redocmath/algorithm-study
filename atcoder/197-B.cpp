#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[100][100];

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    int h, w, x, y; cin >> h >> w >> y >> x;

    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    int cnt = 0;
    for (int i = x; i < w; i++) {
        if (a[y-1][i] == 1) cnt++;
        else break;
    }
    for (int i = x-2; i >= 0; i--) {
        if (a[y-1][i] == 1) cnt++;
        else break;
    }
    for (int i = y-2; i >= 0; i--) {
        if (a[i][x-1] == 1) cnt++;
        else break;
    }
    for (int i = y; i < h; i++) {
        if (a[i][x-1] == 1) cnt++;
        else break;
    }

    cout << cnt+1;
    return 0;
}
