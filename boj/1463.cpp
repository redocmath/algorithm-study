#include <iostream>
#include <algorithm>

using namespace std;

int mem[1000000] = {0, };

// I tried to solve by Top-down solution, but I failed.
// Needs master's help!
int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
	for(int i = 2; i<= N; i++){
		mem[i - 1] = mem[i - 2] + 1;
		if(i % 2 == 0) mem[i - 1] = min(mem[i - 1], mem[i / 2 - 1] + 1);
		if(i % 3 == 0) mem[i - 1] = min(mem[i - 1], mem[i / 3 - 1] + 1);
	}

	cout << mem[N - 1]; 
    return 0;
}
