#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];

    sort(a, a+3);
    cout << a[1];
    return 0;
}
