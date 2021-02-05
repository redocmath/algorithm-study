#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;

        string s;
        cin >> s;

        int uc = 0, dc = 0, rc = 0, lc = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'U') uc++;
            else if (s[i] == 'D') dc++;
            else if (s[i] == 'R') rc++;
            else lc++;
        }

        int xdif, ydif;
        xdif = (rc - lc) - x;
        ydif = (uc - dc) - y;

        if (xdif < 0) {
            if (lc >= abs(xdif)) {
                if (ydif < 0) {
                    if (dc >= abs(ydif)) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                } else {
                    if (uc >= abs(ydif)) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                }
            } else cout << "NO" << "\n";
        } else {
            if (rc >= abs(xdif)) {
                if (ydif < 0) {
                    if (dc >= abs(ydif)) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                } else {
                    if (uc >= abs(ydif)) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                }
            } else cout << "NO" << "\n";
        }
    }
    return 0;
}
