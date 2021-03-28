#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m; cin >> m;
    int s = 0;

    for (int i = 0; i < m; i++) {
        string str; cin >> str;
        if (str == "add") {
            int a; cin >> a;
            s |= (1 << a);
        }
        else if (str == "remove") {
            int a; cin >> a;
            s &= ~(1 << a);
        }
        else if (str == "check") {
            int a; cin >> a;
            if (s & (1 << a)) cout << "1\n"; 
            else cout << "0\n";
        }
        else if (str == "toggle") {
            int a; cin >> a;
            s ^= (1 << a);
        }
        else if (str == "all") {
            s = (1 << 21) - 1;
        } else {
            s = 0;
        }
    }
    return 0;
}
