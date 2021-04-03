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

    deque<int> D;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd; cin >> cmd;
        if (cmd == "push_front") {
            int x; cin >> x;
            D.push_front(x);
        }
        else if (cmd == "push_back") {
            int x; cin >> x;
            D.push_back(x);
        } else if (cmd == "pop_front") {
            if (D.empty()) cout << "-1\n";
            else {
                int x = D.front(); cout << x << "\n";
                D.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (D.empty()) cout << "-1\n";
            else {
                int x = D.back(); cout << x << "\n";
                D.pop_back();
            }
        }
        else if (cmd == "size") {
            cout << D.size() << "\n";
        }
        else if (cmd == "empty") {
            cout << D.empty() << "\n";
        }
        else if (cmd == "front") {
            if (D.empty()) cout << "-1\n";
            else cout << D.front() << "\n";
        }
        else if (cmd == "back") {
            if (D.empty()) cout << "-1\n";
            else cout << D.back() << "\n";
        }
    }
}