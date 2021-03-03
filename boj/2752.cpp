#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; i++) cout << a[i] << " ";
    return 0;
}
