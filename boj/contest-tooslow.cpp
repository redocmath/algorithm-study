#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if (k > n*n-n || (n == 2 && k > 1)) cout << "NO";
    else {
        cout << "YES\n";
        if (n % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (i == (n / 2) - 1) {
                    i = n / 2;
                    for (int j = 0; j < n; j++) {
                        if (i == j || k == 0) cout << ".";
                        else { cout << "#"; k--;}
                    }
                    cout << "\n";
                    i = n / 2 - 1;
                    for (int j = 0; j < n; j++) {
                        if (i == j || k == 0) cout << ".";
                        else { cout << "#"; k--;}
                    }
                    i = n / 2;
                }
                else {
                for (int j = 0; j < n; j++) {
                    if (i == j || k == 0) cout << ".";
                    else { cout << "#"; k--;}
                }
                }
                cout << "\n";
            }
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == (n-1-j) || k == 0) cout << ".";
                else { cout << "#"; k--;}
            }
            cout << "\n";
        }
    }
}
