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
#include <cstring>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    stack<char> st;
    int part = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push('(');
        else {
            st.pop();
            if (s[i-1] == '(') part += st.size();
            else part++;
        }
    }
    cout << part;
}