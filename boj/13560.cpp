#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: idx = " << i << ", value = " << val << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
bool edges[10000][10000];
V scores;


void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; scores.resize(n);

    for (int i = 0; i < n; i++)
        cin >> scores[i];

    sort(scores.begin(), scores.end(), greater<int>());

    solve();
    return 0;
}
