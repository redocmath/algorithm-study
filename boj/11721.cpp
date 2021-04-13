#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    for (int i = 0; i < ceil(s.length()/10); i++) {
        for (int j = 0+10*i; j < 10+10*i; j++) {
            cout << s[j];
        }
        cout << "\n";
    }
    return 0;
}
