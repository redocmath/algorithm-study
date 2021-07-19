#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;

#define D 1
#define U 2
#define R 3
#define L 4
typedef pair<int, int> P;
typedef vector<int> V;

int h, k;
stack<int> command;
vector<bool> v;

void solve() {
    int siv = 2;
    int sih = 2;

    while (!command.empty()){
        int cur = command.top(); command.pop();
        if (cur == D) {
            vector<bool> tmp1(sih);
            vector<vector<bool>> tmp2(siv, tmp1);
            for (int i = 0; i < siv; i++){
                for (int j = 0; j < sih; j++){
                    tmp2[i][j] = v[i*sih+j];
                }
            }
            
            v.clear();
            for (int i = siv-1; i >= 0; i--) {
                for (int j = 0; j < sih; j++) {
                    v.push_back(tmp2[i][j]);
                }
            }
            for (int i = 0; i < siv; i++) {
                for (int j = 0; j < sih; j++) {
                    v.push_back(tmp2[i][j]);
                }
            }
            siv *= 2;
        }
        else if (cur == U) {
            vector<bool> tmp1(sih);
            vector<vector<bool>> tmp2(siv, tmp1);
            for (int i = 0; i < siv; i++){
                for (int j = 0; j < sih; j++){
                    tmp2[i][j] = v[i*sih+j];
                }
            }
            
            v.clear();
            for (int i = 0; i < siv; i++) {
                for (int j = 0; j < sih; j++) {
                    v.push_back(tmp2[i][j]);
                }
            }
            for (int i = siv-1; i >= 0; i--) {
                for (int j = 0; j < sih; j++) {
                    v.push_back(tmp2[i][j]);
                }
            }
            siv *= 2;
        }
        else if (cur == R) {
            vector<bool> tmp1(sih);
            vector<vector<bool>> tmp2(siv, tmp1);
            for (int i = 0; i < siv; i++){
                for (int j = 0; j < sih; j++){
                    tmp2[i][j] = v[i*sih+j];
                }
            }

            v.clear();
            for (int i = 0; i < siv; i++){
                for (int j = sih-1; j >= 0; j--) {
                    v.push_back(tmp2[i][j]);
                }
                for (int j = 0; j < sih; j++) {
                    v.push_back(tmp2[i][j]);
                }
            }
            sih *= 2;
        }
        else if (cur == L) {
            vector<bool> tmp1(sih);
            vector<vector<bool>> tmp2(siv, tmp1);
            for (int i = 0; i < siv; i++){
                for (int j = 0; j < sih; j++){
                    tmp2[i][j] = v[i*sih+j];
                }
            }

            v.clear();
            for (int i = 0; i < siv; i++){
                for (int j = 0; j < sih; j++) {
                    v.push_back(tmp2[i][j]);
                }
                for (int j = sih-1; j >= 0; j--) {
                    v.push_back(tmp2[i][j]);
                }
            }
            sih *= 2;
        }
    }
    // debug
//    for (int i = 0; i < siv; i++){
//        for (int j = 0; j < sih; j++){
//            cout << v[i*sih+j] << " ";
//        }
//        cout << "\n";
//    }

    for (int i = 0; i < siv; i += 2) {
        for (int j = 0; j < sih; j += 2) {
            if (v[i*sih+j]) cout << 0 << " ";
            if (v[i*sih+j+1]) cout << 1 << " ";
            if (v[(i+1)*sih+j]) cout << 2 << " ";
            if (v[(i+1)*sih+j+1]) cout << 3 << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k;

    for (int i = 0; i < 2*k; i++) {
        char t; cin >> t;
        switch (t) {
            case 'D':
                command.push(D);
                break;
            case 'U':
                command.push(U);
                break;
            case 'R':
                command.push(R);
                break;
            case 'L':
                command.push(L);
                break;
        }
    }
    cin >> h;
    v.assign(4, 0);
    v[h] = 1;
    solve();
    return 0;
}
