#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    stack<int> S;

    while (n--) {
        string s; cin >> s;
        if (s == "push") {
            int a; cin >> a;
            S.push(a);
        }
        else if (s == "pop") {
            if (S.empty()) {
                cout << "-1\n";
            } else {
                cout << S.top() << "\n";
                S.pop();
            }
            
        }
        else if (s == "size") {
            cout << S.size() << "\n";
        }
        else if (s == "empty") {
            cout << S.empty() << "\n";
        } else {
            if (S.empty()) cout << "-1\n";
            else cout << S.top() << "\n";
        }
    }
    return 0;
}
