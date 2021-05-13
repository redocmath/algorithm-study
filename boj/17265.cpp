#include <bits/stdc++.h>
#define ADD 6
#define MIN 7
#define MUL 8
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
int board[5][5];
int dp1[5][5][16000];
int dp2[5][5][16000];

int solve_mx(int ver, int hor, int cache) {
    if (ver == n-1 && hor == n-1) return cache;

    int& ret = dp1[ver][hor][cache];
    if (ret != -1) return ret;

    ret = -987654321;

    // | | |
    if (ver + 2 < n) {
        if (board[ver+1][hor] == ADD) 
            ret = max(ret, solve_mx(ver+2, hor, cache+board[ver+2][hor]));
        else if (board[ver+1][hor] == MIN) 
            ret = max(ret, solve_mx(ver+2, hor, cache-board[ver+2][hor]));
        else if (board[ver+1][hor] == MUL) 
            ret = max(ret, solve_mx(ver+2, hor, cache*board[ver+2][hor]));
    }

    // | | L
    if (ver + 1 < n && hor + 1 < n) {
        if (board[ver+1][hor] == ADD) 
            ret = max(ret,solve_mx(ver+1, hor+1, cache+board[ver+1][hor+1]));
        else if (board[ver+1][hor] == MIN) 
            ret = max(ret, solve_mx(ver+1, hor+1, cache-board[ver+1][hor+1]));
        else if (board[ver+1][hor] == MUL) 
            ret = max(ret, solve_mx(ver+1, hor+1, cache*board[ver+1][hor+1]));
    }

    // - - -
    if (hor + 2 < n) {
        if (board[ver][hor+1] == ADD) 
            ret = max(ret, solve_mx(ver, hor+2, cache+board[ver][hor+2]));
        else if (board[ver][hor+1] == MIN) 
            ret = max(ret, solve_mx(ver, hor+2, cache-board[ver][hor+2]));
        else if (board[ver][hor+1] == MUL) 
            ret = max(ret, solve_mx(ver, hor+2, cache*board[ver][hor+2]));
    }

    // - - L
    if (ver + 1 < n && hor + 1 < n) {
        if (board[ver][hor+1] == ADD) 
            ret = max(ret, solve_mx(ver+1, hor+1, cache+board[ver+1][hor+1]));
        else if (board[ver][hor+1] == MIN) 
            ret = max(ret, solve_mx(ver+1, hor+1, cache-board[ver+1][hor+1]));
        else if (board[ver][hor+1] == MUL) 
            ret = max(ret, solve_mx(ver+1, hor+1, cache*board[ver+1][hor+1]));
    }
    return ret;
}

int solve_mn(int ver, int hor, int cache) {
    if (ver == n-1 && hor == n-1) return cache;

    int& ret = dp2[ver][hor][cache];
    if (ret != -1) return ret;
    
    ret = 987654321;

    // | | |
    if (ver + 2 < n) {
        if (board[ver+1][hor] == ADD) 
            ret = min(ret, solve_mn(ver+2, hor, cache+board[ver+2][hor]));
        else if (board[ver+1][hor] == MIN) 
            ret = min(ret, solve_mn(ver+2, hor, cache-board[ver+2][hor]));
        else if (board[ver+1][hor] == MUL) 
            ret = min(ret, solve_mn(ver+2, hor, cache*board[ver+2][hor]));
    }

    // | | L
    if (ver + 1 < n && hor + 1 < n) {
        if (board[ver+1][hor] == ADD) 
            ret = min(ret,solve_mn(ver+1, hor+1, cache+board[ver+1][hor+1]));
        else if (board[ver+1][hor] == MIN) 
            ret = min(ret, solve_mn(ver+1, hor+1, cache-board[ver+1][hor+1]));
        else if (board[ver+1][hor] == MUL) 
            ret = min(ret, solve_mn(ver+1, hor+1, cache*board[ver+1][hor+1]));
    }

    // - - -
    if (hor + 2 < n) {
        if (board[ver][hor+1] == ADD) 
            ret = min(ret, solve_mn(ver, hor+2, cache+board[ver][hor+2]));
        else if (board[ver][hor+1] == MIN) 
            ret = min(ret, solve_mn(ver, hor+2, cache-board[ver][hor+2]));
        else if (board[ver][hor+1] == MUL) 
            ret = min(ret, solve_mn(ver, hor+2, cache*board[ver][hor+2]));
    }

    // - - L
    if (ver + 1 < n && hor + 1 < n) {
        if (board[ver][hor+1] == ADD) 
            ret = min(ret, solve_mn(ver+1, hor+1, cache+board[ver+1][hor+1]));
        else if (board[ver][hor+1] == MIN) 
            ret = min(ret, solve_mn(ver+1, hor+1, cache-board[ver+1][hor+1]));
        else if (board[ver][hor+1] == MUL) 
            ret = min(ret, solve_mn(ver+1, hor+1, cache*board[ver+1][hor+1]));
    }
    return ret;
}
int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            fill(dp1[i][j], dp1[i][j]+16000, -1);
            fill(dp2[i][j], dp2[i][j]+16000, -1);
        }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char s; cin >> s;
            if (s == '+') board[i][j] = ADD;
            else if (s == '-') board[i][j] = MIN;
            else if (s == '*') board[i][j] = MUL;
            else board[i][j] = s - '0';
        }
    }
    cout << solve_mx(0, 0, board[0][0]) << " " << solve_mn(0, 0, board[0][0]);
    return 0;
}
