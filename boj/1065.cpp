#include <iostream>
using namespace std;

int isHan(int n) {
    if (n < 100) return 1;
    int arr[3] = {n / 100, (n / 10) % 10, n % 10};
    if(arr[0] - arr[1] == arr[1] - arr[2]) return 1;
    return 0;
}

int main() {
    int N, count = 0;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        if (isHan(i) == 1)
            count++;
    }
    cout << count;
	return 0;
}
