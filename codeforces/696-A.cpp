#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int n, prv_d; string b; vector<int> a;
        cin >> n >> b;

        for (int j = 0; j < b.length(); j++) {
            if (j == 0) {
                a.push_back(1);
                prv_d = b[j] + a[j];
                continue;
            }
            if (b[j] + 1 == prv_d) {
                a.push_back(0);
                prv_d = b[j];
                continue;
            }
            a.push_back(1);
            prv_d = b[j] + a[j];
        }

        for (int j = 0; j < b.length(); j++) {
            cout << a[j];
        }
        cout << endl;
    }
    return 0;
}

