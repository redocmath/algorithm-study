#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

const int p[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

int n;

int foo[2];

void solve(V tmp, int idx) {
    if (idx == 2) {
        bool isgood = 1;
        for (int i = 0; i < n; i++) {
            if (tmp[i] != i+1) {isgood = 0; break;}
        }
        if (isgood) {
            cout << foo[1] << " " << foo[0];
            return;
        }
        return;
    }
    for (int k = 1; p[k] < n; k++) {
        V ret;
        for (int i = p[k]; i < n; i++) {
            ret.push_back(tmp[i]);
        }
        
        int w = p[k-1];
        stack<int> S;
        for (int i = p[k]-1; i >= 0; i--) {
            S.push(tmp[i]);
            if (i == w) {
                w /= 2;
                while (!S.empty()) {
                    ret.push_back(S.top()); S.pop();
                }
            }
        }

        foo[idx] = k;
        solve(ret, idx+1);
        foo[idx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
    V a;
    for (int i = 0; i < n; i++) {
        int t; cin >> t; a.push_back(t);
    }
    solve(a, 0);
    return 0;
}
