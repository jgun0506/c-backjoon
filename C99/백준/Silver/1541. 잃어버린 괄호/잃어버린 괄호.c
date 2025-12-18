#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int main() {
    char s[400];

    scanf("%s", s);

    int len = strlen(s);
    int total = 0;
    int num = 0;
    
    int sign = 1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '+' || s[i] == '-') {
            total += num * sign;
            if (s[i] == '-')
                sign = -1;
            num = 0;
        }
        else 
            num = num * 10 + (s[i] - '0');
    }
    total += num * sign;
    printf("%d", total);
    return 0;
}  