#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string a; cin >> a;

    int ret = 0, mode = 1; string tmp = ""; bool isToggled = false;
    for (char e: a) {
        if (isdigit(e)) tmp += e;
        else if (e == '+' && !isToggled) {
            ret += mode * stoi(tmp);
            mode = 1;
            tmp = "";
        } else {
            if (!isToggled) isToggled = true;
            ret += mode * stoi(tmp);
            mode = -1;
            tmp = "";
        }
    }
    ret += mode * stoi(tmp);
    cout << ret;
    return 0;
}
