#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

typedef struct _pair {
    int L;
    int J;
} Data;

int n;
Data data[20];

int solve(int heart) {
    int ret = -123456789;
    for (int i = 0; i < n; i++) {
        if (heart - data[i].L <= 0) continue;
        ret = max(ret, data[i].J + solve(heart - data[i].L));
    }
    cout << ret << endl;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> data[i].L;
    for (int i = 0; i < n; i++) cin >> data[i].J;
   
    cout << solve(100);
    return 0;
}
