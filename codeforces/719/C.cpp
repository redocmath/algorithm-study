#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int board[100][100];
bool vis[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        fill(board[i], board[i]+100, 0);

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i]+100, 0);

    board[0][0] = 1;
    queue<P> Q;
    Q.push({0, 0});
    vis[0][0] = 1;

    while (!Q.empty()) {
        P cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nv = cur.first + dy[i];
            int nh = cur.second + dx[i];

            if (nv < 0 || nv >= n || nh < 0 || nh >= n) continue;
            if (vis[nv][nh]) continue;
            board[nv][nh] = 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
