#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    int n; cin >> n;
    int cnt_tp = 0, cnt_fp = 0;
    int twopow = 2, fivepow = 5;
    while (twopow <= n) {
        cnt_tp += n / twopow;
        twopow *= 2;
    }
    while (fivepow <= n) {
        cnt_fp += n / fivepow;
        fivepow *= 5;
    }
    
    cnt_tp = min(cnt_tp, cnt_fp);
    cnt_fp = cnt_tp;

    int a = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = i;
        while (true) {
            if (tmp % 2 == 0 && cnt_tp > 0) {
                tmp /= 2; cnt_tp--;
            }
            if (tmp % 5 == 0 && cnt_fp > 0) {
                tmp /= 5; cnt_fp--;
            }
            if (!(cnt_tp || cnt_fp)) break;
            if (tmp%2 && tmp%5) break;
            if (!(tmp%2) && cnt_tp == 0 && tmp%5) break;
            if (!(tmp%5) && cnt_fp == 0 && tmp%2) break;
        }
        a = (a * tmp) % 10;
    }
    cout << a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
