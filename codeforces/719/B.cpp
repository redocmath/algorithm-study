#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

int solve(int n) {
    if (n < 10) return n;
    else if (n < 100) {
        return 9 + floor(n / 11);
    } else if (n < 1000) {
        return 18 + floor(n / 111);
    }
    else if (n < 10000) {
        return 27 + floor(n / 1111);
    } else if (n < 100000) {
        return 36 + floor(n / 11111);
    }
    else if (n < 1000000) {
        return 45 + floor(n / 111111);
    }
    else if (n < 10000000) {
        return 54 + floor(n / 1111111);
    }
    else if (n < 100000000) {
        return 63 + floor(n / 11111111);
    }
    else if (n <= 1000000000) {
        return 72 + floor(n / 111111111);
    }
}

ll needToCheck(long long n) {
 	long long i, j, r;
    r = 0;
    for (i = 1; i < 10; i++) {
        j = i;
        while (j <= n) {
            j = j * 10 + i;
            r++;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 1e9; i++) {
        if (needToCheck(i) != solve(i)) {
            cout << "DIFFERENT: " << i << "\n";
            break;
        } else {
            cout << "CORRECT: " << i << "\n";
        }
    }
    return 0;
}
