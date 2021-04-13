#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, mp, mf, ms, mu;
int p[15], f[15], s[15], u[15], c[15];
int mn[15], mn_val = 999999999;
int cnt[15]; // 0~n-1
bool isused[15];

void solve(int idx, int last, int leftp, int leftf, int lefts, int leftu, int nowval) {
    if (leftp <= 0 && leftf <= 0 && lefts <= 0 && leftu <= 0) {
        if (nowval < mn_val) {
            fill(mn, mn+15, -1);
            for (int i = 0; i <= idx; i++) {
                mn[i] = cnt[i];
            }
            mn_val = nowval;
        }
    }
    for (int i = last+1; i < n; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            cnt[idx] = i;
            solve(idx+1, i, leftp-p[i], leftf-f[i], lefts-s[i], leftu-u[i], nowval+c[i]);
            cnt[idx] = -1;
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(isused, isused+15, false);
    fill(cnt, cnt+15, -1);
    fill(mn, mn+15, -1);
    cin >> n >> mp >> mf >> ms >> mu;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> f[i] >> s[i] >> u[i] >> c[i];
    }

    solve(0, -1, mp, mf, ms, mu, 0);

    if (mn_val == 999999999) {
        cout << -1;
        return 0;
    }
    cout << mn_val << "\n";
    for (int i = 0; i < n; i++) {
        if (mn[i] == -1) break;
        cout << mn[i]+1 << " ";
    }
    return 0;
}
