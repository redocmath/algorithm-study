#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, start, end) for (int i = (start); i < (end); i++)
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    FOR(i, 0, T) {
        long long N; cin >> N;
        if (N & (N - 1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
