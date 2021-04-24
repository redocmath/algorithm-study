#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
bool a[20][20];
bool vis[20];
const int twopow[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192,16384, 32768, 32768*2, 32768*4, 32768*8, 32768*16, 32768*32};

ll ret = 1;

void solve() {
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (count(a[i], a[i]+20, 1) == 0) ret *= 3;
        else if (count(a[i], a[i]+20, 1) == 1) {
            vis[i] = 1;
            queue<int> Q;
            Q.push(i);

            int cnt = 0;
            while (!Q.empty()) {
                cnt++;
                int cur = Q.front(); Q.pop();
                for (int j = 0; j < n; j++) {
                    if (!a[cur][j] || vis[j]) continue;
                    vis[j] = 1;
                    Q.push(j);
                }
            }
            ret *= 3 * twopow[cnt-1];
        } else {
            vis[i] = 1;
            queue<int> Q;
            Q.push(i);

            int cnt = 0;
            while (!Q.empty()) {
                cnt++;
                int cur = Q.front(); Q.pop();
                for (int j = 0; j < n; j++) {
                    if (!a[cur][j] || vis[j]) continue;
                    vis[j] = 1;
                    Q.push(j);
                }
            }
            ret *= 3 * twopow[cnt-2];
        }
    }
}

int main() {
    for (int i = 0; i < 20; i++) fill(a[i], a[i]+20, 0);
    fill(vis, vis+20, 0);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t1, t2; cin >> t1 >> t2;
        a[t1-1][t2-1] = 1;
        a[t2-1][t1-1] = 1;
    }

    for (int i = 0; i < 20; i++)
        if (count(a[i], a[i]+20, 1) >= 3) {
            cout << "0";
            return 0;
        }

    solve();
    cout << ret;
    return 0;
}
