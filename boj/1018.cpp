#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char chess_1[8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
};

char chess_2[8][8] = {
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B','W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
};

char chess_board[50][50];

int getColoring(int startY, int startX) {
    int coloringCount1 = 0;
    int coloringCount2 = 0;
    for (int i = startY; i < (startY + 8); i++) {
        for (int j = startX; j < (startX + 8); j++) {
            if (chess_board[i][j] != chess_1[i - startY][j - startX]) coloringCount1++;
            if (chess_board[i][j] != chess_2[i - startY][j - startX]) coloringCount2++;
        }
    }

    return (coloringCount1 < coloringCount2 ? coloringCount1 : coloringCount2);
}

int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string intemp; cin >> intemp;
        for (int k = 0; k < m; k++) chess_board[i][k] = intemp[k];
    }

    int minColoring = 999999999;
    for (int i = 0; i <= (n - 8); i++){
        for (int j = 0; j <= (m - 8); j++) {
            int temp = getColoring(i, j);
            if (minColoring > temp) minColoring = temp;
        }
    } 

    cout << minColoring;
    return 0;
}
 
