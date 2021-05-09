#include <bits/stdc++.h>
#define RIGHT 0
#define CROSS 1
#define BOTTOM 2
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
int dp[16][16][3];
bool board[16][16];

int solve(int ver, int hor, int direct) {
    int& tmp =  dp[ver][hor][direct];
    if (ver == n - 1 && hor == n-1) return 1;
    if (tmp != -1) return tmp;

    tmp = 0;
    switch (direct) {
        case RIGHT:
            if (hor+1 < n && !board[ver][hor+1]) tmp += solve(ver, hor+1, RIGHT);
            if (ver+1 < n && hor+1 < n && !board[ver+1][hor] && !board[ver][hor+1]&& !board[ver+1][hor+1]) 
                tmp += solve(ver+1, hor+1, CROSS);
            break;
        case BOTTOM:
            if (ver+1 < n && !board[ver+1][hor]) tmp += solve(ver+1, hor, BOTTOM);
            if (ver+1 < n && hor+1 < n && !board[ver+1][hor] && !board[ver][hor+1]&& !board[ver+1][hor+1]) 
                tmp += solve(ver+1, hor+1, CROSS);
            break;
        case CROSS:
            if (hor+1 < n && !board[ver][hor+1]) tmp += solve(ver, hor+1, RIGHT);
            if (ver+1 < n && !board[ver+1][hor]) tmp += solve(ver+1, hor, BOTTOM);
            if (ver+1 < n && hor+1 < n && !board[ver+1][hor] && !board[ver][hor+1]&& !board[ver+1][hor+1]) 
                tmp += solve(ver+1, hor+1, CROSS);
            break;
    }
    return tmp;
}

int main() {
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            fill(dp[i][j], dp[i][j]+3, -1);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    cout << solve(0, 1, RIGHT);
    return 0;
}
