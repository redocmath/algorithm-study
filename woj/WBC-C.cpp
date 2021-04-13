// editorial
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int k; cin >> k;
    int general = 1, branch = 2;
    for (int i = 1; i < k; i++) {
        int last_gen = general;
        general = (general + branch) % 99999999;
        branch = (last_gen*2) % 99999999;
    }
    cout << general << "\n" << branch;
    return 0;
}
