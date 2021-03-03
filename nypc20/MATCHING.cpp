// now solving 00:03:53 (stop)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

struct tags {
    int idx;
    int value;
};

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int s, k; cin >> s >> k;
    vector<tags> a(n);
    for (int i = 0; i < n; i++) {
        int& tmp = a[i].value; cin >> tmp;
        a[i].idx = i+1;
    }

    tags tmpp {-1, s};
    a.push_back(tmpp);

    sort(a.begin(), a.end());
    for (int i = 0; i < n+1; i++) {
        if (a[i] == s):

    }

    return 0;
}
