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
#include <deque>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int ru1[] = {8, 17, 20, 31, 37, 39, 44, 49, 60, 63};
const int ru2[] = {2, 6, 10, 19, 23, 25, 27, 43};
const int ru3[] = {13, 33, 41, 52, 53, 54};
const int ru5[] = {55, 64};
map<int, int> ru;

int n, x;

int dp[65][1001];

int get(int pos, int left) { return ru[pos]+solve(pos, left-1); }
int solve(int pos, int left) {
    int& res = dp[pos][left];
    if (res != -1) return res;
    if (!left) return pos == x ? 0 : -1000000000;
    // exception
    if (7 <= pos && pos <= 12) {
        for (int i = pos+1; i <= pos+6; i++) {
            if (i == 12) {
                for (int j = 0; j <= pos-7; j++) res = max(res, get(17+j, left));
            }
            res = max(res, get(i, left));
        }
    }
    return res = max({
        get(pos%64+1, left),
        get((pos+1)%64+1, left),
        get((pos+2)%64+1, left),
        get((pos+3)%64+1, left),
        get((pos+4)%64+1, left),
        get((pos+5)%64+1, left),
    });
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= 64; i++) {
        if (find(ru1, ru1+10, i) != ru1+10) ru[i] = 1;
        else if (find(ru2, ru2+8, i) != ru2+8) ru[i] = 2;
        else if (find(ru3, ru3+6, i) != ru3+6) ru[i] = 3;
        else if (find(ru5, ru5+2, i) != ru5+2) ru[i] = 5;
        else ru[i] = 0;
    }
    cout << solve(1, n);
}