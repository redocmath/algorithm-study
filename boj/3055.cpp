#include <bits/stdc++.h>
#define EMPTY 0
#define D 1
#define S 2
#define X 3
#define WATER 4
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int dh[] = {1, 0, -1, 0};
int dv[] = {0, 1, 0, -1};

int r, c;
int board[50][50];
int vis[50][50];
int vis_h[50][50];
queue<P> hedgepos;
queue<P> waterpos;

void solve() {
    P cur;
    while (!waterpos.empty()) {
        cur = waterpos.front(); waterpos.pop();
        for (int i = 0; i < 4; i++) {
            int nv = cur.first + dv[i];
            int nh = cur.second + dh[i];
            if (nv < 0 || nv >= r || nh < 0 || nh >= c) continue;
            if (vis[nv][nh] != -1 || board[nv][nh] != EMPTY) continue;
            vis[nv][nh] = vis[cur.first][cur.second]+1;
            waterpos.push(P(nv, nh));
        }
    }

    int ret = -1;
    while (!hedgepos.empty()) {
        cur = hedgepos.front(); hedgepos.pop();
        for (int i = 0; i < 4; i++) {
            int nv = cur.first + dv[i];
            int nh = cur.second + dh[i];
            if (nv < 0 || nv >= r || nh < 0 || nh >= c) continue;
            if (board[nv][nh] == D) {ret = vis_h[cur.first][cur.second]+1; cout << ret; return;}
            if (vis_h[nv][nh] != -1 || vis[nv][nh] <= vis_h[cur.first][cur.second]+1 || board[nv][nh] != EMPTY) continue;
            vis_h[nv][nh] = vis_h[cur.first][cur.second]+1;
            hedgepos.push(P(nv, nh));
        }
    }
    cout << "KAKTUS";
}

int main() {
    for (int i = 0; i < 50; i++) fill(vis[i], vis[i]+50, -1);
    for (int i = 0; i < 50; i++) fill(vis_h[i], vis_h[i]+50, -1);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '.') board[i][j] = EMPTY;
            if (s[j] == 'D') board[i][j] = D;
            if (s[j] == 'S') {
                board[i][j] = S;
                hedgepos.push(P(i, j));
                vis_h[i][j] = 0;
            }
            if (s[j] == 'X') board[i][j] = X;
            if (s[j] == '*') {
                board[i][j] = WATER;
                waterpos.push(P(i, j));
                vis[i][j] = 0;
            }
        }
    }
    solve();
    return 0;
}
