#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int D[1000005];
int save[1000005];

int mn(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    D[1] = 0;
    D[2] = 1;
    D[3] = 1;
    save[1] = 0;
    save[2] = 1;
    save[3] = 1;
    for (int i = 4; i <= n; i++) {
        D[i] = D[i - 1] + 1;
        if (i % 2 == 0) 
            D[i] = mn(D[i], D[i / 2] + 1);
        if (i % 3 == 0)
            D[i] = mn(D[i], D[i / 3] + 1);

        if (D[i] == (D[i - 1] + 1))
            save[i] = i - 1;
        if (i % 2 == 0 && D[i] == (D[i / 2] + 1))
            save[i] = i / 2;
        if (i % 3 == 0 && D[i] == (D[i / 3] + 1))
            save[i] = i / 3;

    }

    
    printf("%d\n", D[n]);
    printf("%d ", n);
    int a = n;
    
    for (int i = 0; i < D[n]; i++) {
        printf("%d ", save[a]);
        a = save[a];
    }

    return 0;
}