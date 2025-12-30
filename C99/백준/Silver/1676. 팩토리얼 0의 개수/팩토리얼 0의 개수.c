#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int main() {

    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 5; i <= n; i++) {
        int five = i;
        while (five%5==0) {
            five /= 5;
            count++;
        }
    }
    printf("%d", count);

    

    return 0;
}  