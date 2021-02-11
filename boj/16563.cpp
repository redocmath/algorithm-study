// unsuccessful
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
typedef long long ll;
using namespace std;

int isPrime[5000001];

int main() {
    ios::sync_with_stdio(false);
	memset(isPrime, 1, 5000001);
    for(int i = 2; i <= sqrt(5000000); i++){
        if (isPrime[i]) {
            for(int j = 2 * i; j < 5000000; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        cout << "\n";
    }
    return 0;
}
