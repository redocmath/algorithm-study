/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct relative {
    vector<int> score;
};

int main() {
    int N;
    vector<int> X, Y;
    vector<struct relative> relativeScore;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X.push_back(x); Y.push_back(y);
    }

    for (int i = 0; i < N; i++) {
        struct relative tempRelScore;
        for (int j = 0; j < N; j++){
            if (X[i] < X[j] && Y[i] < Y[j]) tempRelScore.score.push_back(1);
            else tempRelScore.score.push_back(0);
        }
        relativeScore.push_back(tempRelScore);
    }

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) if (relativeScore[i].score[j] == 1) count++;
        cout << (count + 1) << " ";
    }
    return 0;
}