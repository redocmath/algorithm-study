#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
    return 0;
}
