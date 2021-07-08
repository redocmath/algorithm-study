#include <bits/stdc++.h>
#define L 1
#define W 0
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int ver, hor;
bool board[51][51];
int mx = -1;

int dv[] = {0, 1, 0, -1};
int dh[] = {1, 0, -1, 0};

void solve() {
    for (int i = 0; i < ver; i++)
        for (int j = 0; j < hor; j++) {
            if (board[i][j] == W) continue;
            int vis[51][51]; memset(vis, 0, sizeof(vis));

            queue<P> Q;
            Q.push({i, j});
            vis[i][j] = 1;

            int t = 0;
            while (!Q.empty()) {
                P cur = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++) {
                    int nv = cur.first + dv[k];
                    int nh = cur.second + dh[k];

                    if (nv < 0 || nv >= ver || nh < 0 || nh >= hor) continue;
                    if (board[nv][nh] == W || vis[nv][nh]) continue;
                    
                    vis[nv][nh] = vis[cur.first][cur.second]+1;
                    t = max(t, vis[nv][nh]);
                    Q.push({nv, nh});
                }
            }
//            cout << i << " " << j << " -> " << t << "\n";
            mx=max(mx, t-1);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ver >> hor;
    for (int i = 0; i < ver; i++) {
        string s; cin >> s;
        for (int j = 0; j < hor; j++) {
            board[i][j] = (s[j] == 'L' ? L : W);
        }
    }
    solve();
    cout << mx;
    return 0;
}
