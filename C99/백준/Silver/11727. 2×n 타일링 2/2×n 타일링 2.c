#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int D[1005];

int main() {
    int n;
    scanf("%d", &n);

    D[1] = 1;
    D[2] = 3;
    
    for (int i = 3; i <= n; i++) {
        D[i] = D[i - 1] + 2 * D[i - 2];
        D[i] %= 10007;
    }

    printf("%d", D[n]);

    return 0;
}  