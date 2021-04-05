#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;

    bool isposs = false;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] != s[i+1]) {
            isposs = true;
            break;
        }
    }

    if (!isposs) {
        cout << "-1\n";
        return 0;
    }

    bool isPal = true;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            isPal = false;
            break;
        }
    }

    if (isPal) cout << s.length() - 1;
    else cout << s.length();
}