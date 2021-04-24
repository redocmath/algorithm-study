#include <bits/stdc++.h>
#include <cstring>
#include <string>
typedef long long ll;
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    string s;
    cin >> n >> s >> q;
    while (q--) {
        int t, a, b; scanf("%d %d %d", &t, &a, &b);
        if (t == 1) {
            char tmp = s[a-1];
            s[a-1] = s[b-1];
            s[b-1] = tmp;
        }
        else {
            s = s.substr(n) + s.substr(0, n);
        }
    }

    printf("%s", s.c_str());
    return 0;
}
