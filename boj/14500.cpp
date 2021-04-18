#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m; // ver hor
int board[500][500];
bool vis[500][500];

int ret = -1;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solve(int ver, int hor, int k) {
    if (k == 4) {
        return 0;
    }

    int tmp = -1;
    for (int i = 0; i < 4; i++) {
        int nv = ver + dy[i];
        int nh = hor + dx[i];
        if (nv < 0 || nv >= n || nh < 0 || nh >= m) continue;
        if (vis[nv][nh]) continue;
        vis[nv][nh] = true;
        tmp = max(tmp, board[nv][nh] + solve(nv, nh, k+1));
        vis[nv][nh] = false;
    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 500; i++)
        fill(vis[i], vis[i]+500, false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            vis[i][j] = true;
            ret = max(ret, board[i][j] + solve(i, j, 1));
            vis[i][j] = false;
            
            // case work: 
            //     []
            //  r--  --q
            //  L______Q

            if (i+1 < n && j+2 < m) ret = max(ret, board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1]);
            if (i-1>=0 && i+1 < n && j+1 < m) ret = max(ret, board[i][j] + board[i][j+1] + board[i-1][j+1] + board[i+1][j+1]);
            if (i+2 < n && j+1 < m) ret = max(ret, board[i][j] + board[i+1][j+1] + board[i+1][j] + board[i+2][j]);
            if (i-1 >= 0 && j+2 < m) ret = max(ret, board[i][j] + board[i][j+1] + board[i][j+2] + board[i-1][j+1]);
        }

    cout << ret;
    return 0;
}
