#include <algorithm>
#include <iostream>
#define MAX 15

using namespace std;

int N, T[MAX], P[MAX];

int getBestPlan(int day) {
    if (day > N) return 0;
    if (day + T[day - 1] - 1 > N) return getBestPlan(day + 1);
    return max(P[day-1] + getBestPlan(day + T[day - 1]), getBestPlan(day + 1));
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    cout << getBestPlan(1);
    return 0;
}
