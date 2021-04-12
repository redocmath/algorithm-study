#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = n-i; j > 0; j--) cout << "*";
        cout << "\n";
    }
    return 0;
}
