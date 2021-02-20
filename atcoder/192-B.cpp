#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    bool isGood = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 97 && i % 2 == 1) {
            isGood = false;
            break;
        }
        if (s[i] < 97 && i % 2 == 0) {
            isGood = false;
            break;
        }
    }
    cout << (isGood ? "Yes" : "No");
    return 0;
}
