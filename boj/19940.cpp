#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int addh = 0, addt = 0, mint = 0, addo = 0, mino = 0;
        int n; cin >> n;
        if (n > 60) {
            addh += floor(n / 60);
            n %= 60;
        }
        if (n > 35) {
            addh++;
            n = 60 - n;
            mint += floor(n / 10);
            n %= 10;
            if (n > 5) {
                mint++;
                addo += 10-n;
            } else {
                mino += n;
            }
        } else {
            addt += floor(n / 10);
            n %= 10;
            if (n > 5) {
                addt++;
                mino += 10-n;
            } else {
                addo += n;
            }
        }
        cout << addh << " " << addt <<" " << mint << " " << addo << " " << mino << "\n";
    }
}
