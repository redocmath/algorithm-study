#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        string n; cin >> n;
        for (int j = stol(n); j > 0; j--) {
            string s = to_string(j);
            string ss = s;
            sort(ss.begin(), ss.end());
            if (s == ss) {
                cout << "Case #" << i << ": " << s << endl;
                break;
            }
        }
    }
    return 0;
}
