#include <cstdio>

int max(int a, int b) { return a > b ? a : b; }
int main() {

    int N, i, j, ans = 0;

    int dp[1000];
    int arr[1000];

    scanf("%d", &N);

    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    for (i = 0; i < N; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] < arr[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
    }

    for (i = 0; i < N; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);

    return 0;
}

