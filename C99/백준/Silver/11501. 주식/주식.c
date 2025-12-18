#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int arr[1000005];
int high[1000005];

int mx(int a, int b) {
    return a > b ? a : b;
}


int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        memset(high, 0, sizeof(high));

        int max = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max = mx(max, arr[i]);
            high[i] = max;
        }
        long long total = 0;
        for (int i = 0; i < n; i++) {
            if (high[i] >= arr[i]) {
                total += high[i] - arr[i];
            }
            else {
                continue;
            }
        }
        printf("%lld\n", total);
    }

    return 0;
}  