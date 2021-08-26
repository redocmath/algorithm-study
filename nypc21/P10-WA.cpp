#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: idx = " << i << ", value = " << val << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int N, K;
int C[5000][5000];

long solve() {
    if (K == 1) return 0;
    for (int i = 0; i < N-1; i++)
        C[1][i] = C[0][i]-C[0][i+1];
    
    if (K > 2) {
        for (int i = 0; i < N-2; i++)
            C[2][i] = C[1][i]+C[1][i+1];

        for (int i = 3; i < K; i++)
            for (int j = 0; j < N-(K-1); j++)
                C[i][j] = C[i-1][j]+C[1][j+2];
    }

    long mx = LONG_MIN, ret = 0;
    for (int i = 0; i < N-K+1; i++) {
        for (int j = 1; j < K; j++) {
            for (int l = i; l < i+K-j; l++) {
                ret += abs(C[j][l]);
            }
        }
        mx = max(mx, ret);
        ret = 0;
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> C[0][i];
    }
    cout << solve();
    return 0;
}
