#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        stack<bool> a;
        string s; cin >> s;
        bool was_dead = false;
        for (char ss: s) {
            if (ss == '(') a.push(true);
            if (ss == ')') {
                if (a.empty()) {
                    cout << "NO\n";
                    was_dead = true;
                    break;
                }
                a.pop();
            }
        }
        if (was_dead) continue;
        if (a.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
