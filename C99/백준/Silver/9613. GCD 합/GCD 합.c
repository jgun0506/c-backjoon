#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int num[105];
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {

    int t, n;
    scanf("%d", &t);

    while (t--) {
        long long sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(num[i], num[j]);
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}  