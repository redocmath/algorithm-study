#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: idx = " << i << ", value = " << val << "\e[m\n"
#define FAILED(n, f, m, expected, real) "\e[31mTEST FAILED: n = " << n << ", f = " << f << ", m = " << m << "\nexpected: " << expected << ", result: " << real << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, f, m;

int solve() {
    // Method 1: start from 1
    int boo = (1 != f), nn = n;
    if (m-1 >= nn) boo += (nn+1 != f);
    else {
        boo++; nn -= m-1;
        boo += nn / (m-1) - (nn % (m-1) == 0);
        nn %= m-1;
        boo += !((nn == 0 && f == m) || (nn != 0 && nn + 1 <= f));
    }

    // Method 2: start from me
    int foo = 0; nn = n;
    if (m-f >= nn) foo += 1;
    else {
        foo++; nn -= m-f;
        foo += nn / (m-1) - (nn % (m-1) == 0);
        nn %= (m-1);
        foo += !((nn == 0 && f == m) || (nn != 0 && nn + 1 <= f));
    }
    
    return min(foo, boo);
}

int nieve() {
    int mn = INT_MAX;
    for (int i = 1; i <= m; i++) {
        int cur = i, tmp = (i != f), nn = n;
        while (nn > 0) {
            if (cur == m) {
                tmp++;
                cur = 1;
                continue;
            }
            cur++;
            nn--;
        }
        if (cur > f) tmp++;
//        cout << DEBUG(i, tmp);
        mn = min(tmp, mn);
    }
    return mn;
}

void Scaffold() {
    int count_err = 0;
    for (int i = 2; i <= 100; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= 3*i; k++) {
                m = i, f = j, n = k;
                if (solve() != nieve()) {
                    cout << FAILED(n, f, m, nieve(), solve());
                    count_err++;
                }
            }
    cout << "Found " << count_err << " fail";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    Scaffold();
    cin >> m >> f >> n;
    cout << solve();
    return 0;
}
