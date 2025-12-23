#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

bool state[1000001] = { true, };

void sieve(int n) {
    state[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i)
            state[j] = false;
    }
}

int main() {
    int m, n;
    
    scanf("%d %d", &m, &n);
    memset(state, 1, sizeof(state));

    sieve(n);
    for (int i = m; i <= n; i++) {
        if (state[i])
            printf("%d\n", i);
    }

    return 0;
}  