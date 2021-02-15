#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string n; cin >> n;
    if (find(n.begin(), n.end(), 0) == n.end()) cout << "-1";

    else {
        sort(n.begin(), n.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < n.length(); i++) sum += n[i] - '0';
    }
    return 0;
}
