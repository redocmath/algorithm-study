#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int solve(int h, int y) {
    if (y == 0) return h;

    if (y < 3)
        return solve(floor(h * 105 / 100), y - 1);
    if (y < 5)
        return max(solve(floor(h * 105 / 100), y - 1), solve(floor(h * 120 / 100), y - 3));
    return max(max(solve(floor(h * 105 / 100), y - 1), solve(floor(h * 120 / 100), y - 3)), solve(floor(h * 135 / 100), y - 5));
}

int main() {
    ios::sync_with_stdio(false);
    int h, y; cin >> h >> y;

    cout << solve(h, y);
    return 0;
}
