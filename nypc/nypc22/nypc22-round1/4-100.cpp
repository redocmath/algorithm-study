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

int n, x;

const int ru1[] = {8, 17, 20, 31, 37, 39, 44, 49, 60, 63};
const int ru2[] = {2, 6, 10, 19, 23, 25, 27, 43};
const int ru3[] = {13, 33, 41, 52, 53, 54};
const int ru5[] = {55, 64};
map<int, int> ru;

// graph dp 적용?
vector<P> v({
    {1 , 2}, 
    {2 , 3}, 
    {3 , 4}, 
    {4 , 5}, 
    {5 , 6}, 
    {6 , 7}, 
    {7 , 8}, 
    {8 , 9}, 
    {9 , 10}, 
    {10 , 11}, 
    {11 , 12}, 
    {12 , 13}, 
    {12 , 17}, 
    {13 , 14}, 
    {14 , 15}, 
    {15 , 16}, 
    {16 , 17}, 
    {17 , 18}, 
    {18 , 19}, 
    {19 , 20}, 
    {20 , 21}, 
    {21 , 22}, 
    {22 , 23}, 
    {23 , 24}, 
    {24 , 25}, 
    {25 , 26}, 
    {26 , 27}, 
    {27 , 28}, 
    {28 , 29}, 
    {29 , 30}, 
    {30 , 31}, 
    {31 , 32}, 
    {32 , 33}, 
    {32 , 37}, 
    {33 , 34}, 
    {34 , 35}, 
    {35 , 36}, 
    {36 , 37}, 
    {37 , 38}, 
    {38 , 39}, 
    {39 , 40}, 
    {39 , 41}, 
    {40 , 44}, 
    {41 , 42}, 
    {42 , 43}, 
    {43 , 40}, 
    {44 , 45}, 
    {45 , 46}, 
    {46 , 47}, 
    {47 , 48}, 
    {48 , 49}, 
    {49 , 50}, 
    {49 , 52}, 
    {49 , 56}, 
    {50 , 51}, 
    {51 , 60}, 
    {52 , 53}, 
    {53 , 54}, 
    {54 , 55}, 
    {55 , 51}, 
    {56 , 57}, 
    {57 , 58}, 
    {58 , 59}, 
    {59 , 51}, 
    {60 , 61}, 
    {61 , 62}, 
    {62 , 63}, 
    {63 , 64}, 
    {64 , 1}, 
});

vector<int> graph[65];
int dp[65][1001];
int choice[65][1001];
int dice[65][1001];

int solve(int pos, int left) {
    int &res = dp[pos][left];
    if (res != -1) return res;
    if (!left) return (pos == x ? 0 : -1000000000);

    res = -1000000000;
    int best = -1000000000;
    int _dice = -1;
    queue<P> Q; Q.push({pos, 6});
    while (!Q.empty()) {
        P cur = Q.front(); Q.pop();
        if (cur.second != 6 && ru[cur.first]+solve(cur.first, left-1) >= res && ru[cur.first]+solve(cur.first, left-1) >= 0) {
            res = ru[cur.first]+solve(cur.first, left-1);
            best = cur.first;
            _dice = 6-cur.second;
        }
        if (!cur.second) continue;
        for (int i = 0; i < graph[cur.first].size(); i++) {
            Q.push({graph[cur.first][i], cur.second-1});
        }
    }

    // cout << "solve(" << pos << "," << left << ") = " << best << "\n";
    choice[pos][left] = best;
    dice[pos][left] = _dice;

    return res;
}

vector<int> seq;
vector<int> diceseq;

void construct(int pos, int left) {
    if (!left) {
        // cout << "completed"; 
        return;
    }
    if (choice[pos][left] < 0) return;
    seq.push_back(choice[pos][left]);
    diceseq.push_back(dice[pos][left]);
    // cout << choice[pos][left] << " -> ";
    construct(choice[pos][left], left-1);
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(choice, -1, sizeof(choice));
    memset(dice, -1, sizeof(dice));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> x; 
    for (P ele: v) {
        graph[ele.first].push_back(ele.second);
    }

    for (int i = 1; i <= 64; i++) {
        if (find(ru1, ru1+10, i) != ru1+10) ru[i] = 1;
        else if (find(ru2, ru2+8, i) != ru2+8) ru[i] = 2;
        else if (find(ru3, ru3+6, i) != ru3+6) ru[i] = 3;
        else if (find(ru5, ru5+2, i) != ru5+2) ru[i] = 5;
        else ru[i] = 0;
    }
    cout << solve(1, n) << "\n";
    seq.push_back(1);
    construct(1, n);

    for (int i = 0; i < n; i++)
        cout << "Moved from " << seq[i] << " to " << seq[i+1] << " (dice = " << diceseq[i] << ", lucci = " << ru[seq[i+1]] << ")\n";
}