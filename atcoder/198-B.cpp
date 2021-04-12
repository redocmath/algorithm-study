#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;

    bool isPal = true;
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length()-i-1]) {
            isPal = false;
            break;
        }
    }

    if (isPal) {
        cout << "Yes";
        return 0;
    }

    int cnt;
    for (cnt = s.length()-1; cnt >= 0; cnt--) {
        if (s[cnt] != '0') break;
    }

    string a = "";
    for (int i = 0; i < cnt+1; i++) {
        a += s[i];
    }

    isPal = true;
    for (int i = 0; i < a.length()/2; i++) {
        if (a[i] != a[a.length()-i-1]) {
            isPal = false;
            break;
        }
    }

    if (isPal) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
