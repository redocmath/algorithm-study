#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 300
using namespace std;

int N;
int points[MAX]; int caches[MAX];

int main() {
    for (int i = 0; i < MAX; i++) {
        caches[i] = -1;
    }

    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    // better to solve bottom-up
    caches[0] = points[0];
    caches[1] = max(points[0]+points[1], points[1]);
    caches[2] = max(points[0]+points[2], points[1]+points[2]);

    for(int i = 3; i < N; i++) {
        caches[i] = max(caches[i - 2] + points[i], caches[i - 3] + points[i] + points[i - 1]); 
    }

    cout << caches[N - 1];
    return 0;
}
