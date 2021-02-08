#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
    return (a % b ? gcd(b, a%b) : b);
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int m = nums[1] - nums[0];
    for (int i = 1; i < n - 1; i++) {
        m = gcd(m, nums[i+1] - nums[i]);
    }

    vector<int> ans;

    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            ans.push_back(i);
            if (i != m / i) ans.push_back(m/i);
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
