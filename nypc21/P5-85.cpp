#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int ver, hor; // n, m
int canvas[101][101];
int needs[101][101];
int mxofcolumn[101];
vector<string> commands;

void solve() {
    while (1) {
        bool isfinished = 1;
        for (int i = 0; i < ver; i++) {
            vector<int> diff;
            for (int j = 0; j < hor; j++) {
                if (!needs[i][j]) continue;
                if (canvas[i][j] != needs[i][j]) diff.push_back(j);
            }
            if (diff.size() == 0) continue;
            isfinished = 0;
            commands.push_back("H " + to_string(i+1) + " " + to_string(mxofcolumn[i]));
            for (int j = 0; j < hor; j++) canvas[i][j] = mxofcolumn[i];
            diff.clear();
            for (int j = 0; j < hor; j++) {
                if (!needs[i][j]) continue;
                if (canvas[i][j] != needs[i][j]) diff.push_back(j);
            }
            if (diff.size() == 0) continue;
            for (int j: diff) {
                commands.push_back("V " + to_string(j+1) + " " + to_string(needs[i][j]));
                for (int k = 0; k < ver; k++) {
                    canvas[k][j] = needs[i][j];
                }
            }
        }

        if (isfinished) break;
    }
}

void nsolve() {
    while (1) {
        bool isfinished = 1;
        for (int i = 0; i < ver; i++) {
            vector<int> diff;
            for (int j = 0; j < hor; j++) {
                if (!needs[i][j]) continue;
                if (canvas[i][j] != needs[i][j]) diff.push_back(j);
            }
            if (diff.size() == 0) continue;
            isfinished = 0;
            commands.push_back("H " + to_string(i+1) + " " + to_string(mxofcolumn[i]));
            for (int j = 0; j < hor; j++) canvas[i][j] = mxofcolumn[i];
            diff.clear();
            for (int j = 0; j < hor; j++) {
                if (!needs[i][j]) continue;
                if (canvas[i][j] != needs[i][j]) diff.push_back(j);
            }
            if (diff.size() == 0) continue;
            for (int j: diff) {
                commands.push_back("V " + to_string(j+1) + " " + to_string(needs[i][j]));
                for (int k = 0; k < ver; k++) {
                    canvas[k][j] = needs[i][j];
                }
            }
        }

        if (isfinished) break;
    }
}


int main() {
    memset(canvas, 0, sizeof(canvas));
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ver >> hor;
    for (int i = 0; i < ver; i++) {
        vector<int> a(8, 0);
        for (int j = 0; j < hor; j++) {
            cin >> needs[i][j];
            if (needs[i][j])
                a[needs[i][j]]++;
        }
        int mx = 1, mx_co = a[1];
        for (int j = 2; j < 8; j++) {
            if (mx_co < a[j]) {
                mx = j; mx_co = a[j];
            }
        }
        mxofcolumn[i] = mx;
    }
    solve(); // works on n <= 60
    if (commands.size() > 10000) {
        cout << "\e[31mK > 10000. Stop here :(\e[m";
        return 0;
    }

    std::ofstream outf("test.txt");

    if (outf.is_open()) {
        outf << commands.size() << "\n";
        for (string e: commands) outf << e << "\n";
    }
    return 0;
}
