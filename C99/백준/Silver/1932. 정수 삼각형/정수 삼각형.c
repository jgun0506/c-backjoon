#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int a[505][505];
int d[505][505];

int mx(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    d[1][1] = a[1][1];
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i][j] = mx(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
        }
    }
    int max = d[n][1];
    for (int i = 2; i <= n; i++) {
        if (max < d[n][i])
            max = d[n][i];
    }

    printf("%d", max);
    
    return 0;
}