#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <functional>
#define MAX 500
using namespace std;

int n, k, a[MAX];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    double ret = 123456789;

    while (k <= n) {
        for (int i = 0; i <= n-k; i++) {
            double avg = 0;
            for (int j = i; j < i+k; j++) avg += a[j];
            avg /= k;

            double tmp = 0;
            for (int j = i; j < i+k; j++) tmp += (a[j] - avg) * (a[j] - avg);

            tmp /= k;
            if (ret > sqrt(tmp)) ret = sqrt(tmp);
        }
        k++;
    }

    cout << setprecision(10) << ret;

    return 0;
}
