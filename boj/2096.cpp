#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int N;
short arr[100000][3];

int getMax() {
    int dpa = arr[N-1][0], dpb = arr[N-1][1], dpc = arr[N-1][2];
    for (int n = N-2; n >= 0; n--) {
        int upda, updb, updc;
        upda = max(dpa, dpb) + arr[n][0];
        updb = max({dpa, dpb, dpc}) + arr[n][1];
        updc = max(dpb, dpc) + arr[n][2];
        dpa = upda, dpb = updb, dpc = updc;
    }
    return max({dpa, dpb, dpc});
}

int getMin() {
    int dpa = arr[N-1][0], dpb = arr[N-1][1], dpc = arr[N-1][2];
    for (int n = N-2; n >= 0; n--) {
        int upda, updb, updc;
        upda = min(dpa, dpb) + arr[n][0];
        updb = min({dpa, dpb, dpc}) + arr[n][1];
        updc = min(dpb, dpc) + arr[n][2];
        dpa = upda, dpb = updb, dpc = updc;
    }
    return min({dpa, dpb, dpc});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    
    cout << getMax() << " " << getMin();
}