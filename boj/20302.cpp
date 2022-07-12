#include <bits/stdc++.h>
#define DEBUG(i, val) "\e[33mDEBUG: idx = " << i << ", value = " << val << "\e[m\n"
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n; V num; vector<bool> opr; // t: *, f: /

void solve() {
    V prime; vector<bool> isprime(100001, true);
    isprime[0] = 0; isprime[1] = 0;
    for (int i = 2; i < 100001; i++) {
        prime.push_back(i);
        if (isprime[i])
            for (int j = i*2; j < 100001; j+=i) isprime[j] = 0;
    }

    V decom(prime.size());

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; num.push_back(a);
        int b; cin >> b; num.push_back((b == '*' ? 1 : 0));
    }
    solve();
    return 0;
}
