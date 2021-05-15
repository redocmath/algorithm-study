#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int n;
bool sieve[4000001];
vector<int> prime;

void solve() {
    int cnt = 0, s = 0, lo = 0, hi = 0;
    while (1) {
        if (s >= n) s -= prime[lo++];
        else if (hi == prime.size()) break;
        else s += prime[hi++];
        if (s == n) cnt++;
    }
    cout << cnt;
}

int main() {
    fill(sieve, sieve+4000001, 1);
    sieve[1] = 0;
    for (int i = 2; i <= 4000000; i++) {
        if (sieve[i]) prime.push_back(i);
        for (int j = i*2; j <= 4000000; j += i) {
            sieve[j] = 0;
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    solve();
    return 0;
}
