#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#define MAX 36
typedef long long ll;
using namespace std;

long long t[MAX];

int main() {
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    t[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            t[i] += t[j] * t[i - 1 - j];
        }
    }

    cout << t[n];
    return 0;
}
