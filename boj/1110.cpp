#include <iostream>
using namespace std;

int main()
{
    int N, count = 0;
    cin >> N;
    if (N < 10) N *= 10;
    
    const int realN = N;
    
    do {
        N = (N % 10) * 10 + (N / 10 + N % 10) % 10;
        count += 1;
    }while (realN != N);
    
    cout << count;
    return 0;
}
