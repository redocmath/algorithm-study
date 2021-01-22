#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string temp;
        int score = 0;
        cin >> temp;
        
        int acc = 1;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 'O') {
                score += acc;
                acc += 1;
            }else {
                acc = 1;
            }
        }
        cout << score << endl;
    }
    
    return 0;
}