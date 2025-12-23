#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>


bool isprime(int a) {
    if (a == 1)
        return 0;

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;

}

int main() {
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    for (int i = m; i <= n; i++) {
        if (isprime(i)) {
            printf("%d\n", i);
        }
    }



    return 0;
}  