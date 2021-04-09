// try again
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, ret;
int a[11];
int pl_, mi_, mu_, di_; // + - * /
char cal[10];

ll mn = 1000000001, mx = -1000000001;

ll calc() {
    ll tmp = 0, cache = a[0]; // storage, cache
    int mode = 1;
    for (int i = 0; i < n-1; i++) {
        if (cal[i] == '+') {
            tmp += cache * mode;
            cache = a[i+1];
            mode = 1;
        } else if (cal[i] == '-') {
            tmp += cache * mode;
            cache = a[i+1];
            mode = -1;
        } else if (cal[i] == '*') {
            cache *= a[i+1];
        } else {
            cache /= a[i+1];
        }
    }
    return tmp + cache * mode;
}
void solve(int n_, int pl, int mi, int mu, int di) {
    if (n_ == n-1) {
        for (int i = 0; i < n-1; i++) {
            cout << a[i] << cal[i];
        }
        ll cur = calc();
        cout << a[n-1] << "=" << cur << "\n";
        if (cur < mn) mn = cur;
        if (cur > mx) mx = cur;
    }
    if (pl != 0) { cal[n] = '+'; solve(n+1, pl-1, mi, mu, di); }
    if (mi != 0) { cal[n] = '-'; solve(n+1, pl, mi-1, mu, di); }
    if (mu != 0) { cal[n] = '*'; solve(n+1, pl, mi, mu-1, di); }
    if (pl != 0) { cal[n] = '/'; solve(n+1, pl, mi, mu, di-1); }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> pl_ >> mi_ >> mu_ >> di_;

    solve(0, pl_, mi_, mu_, di_);
    cout << mx << "\n" << mn;
    return 0;
}
