#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int board[100][100];
bool vis[100];

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        board[a-1][b-1] = 1;
        board[b-1][a-1] = 1;
    }
    queue<int> Q;
    vis[0] = true;
    Q.push(0);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < n; i++) {
            if (i != cur && board[cur][i] && !vis[i]) {
                vis[i] = true;
                Q.push(i);
            }
        }
    }

    cout << count(vis, vis+n, true)-1;
    return 0;
}
