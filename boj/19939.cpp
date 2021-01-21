#include <iostream>
#include <string>
#include <vector>

// sum from 1 to a
#define SUM(a) a * (a + 1) / 2

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;

    if (K > N || SUM(K) > N) cout << "-1";
    else {
        int dmax = (N - SUM(K)) % K == 0 ? 0 : 1;
        cout << K + dmax - 1;
    }

    return 0;
}
