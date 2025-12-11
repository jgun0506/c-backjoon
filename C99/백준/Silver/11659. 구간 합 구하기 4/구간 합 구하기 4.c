#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>




int main() {
    
    int n, m;
    int s[100005];
    scanf("%d %d", &n, &m);
    int a;
    scanf("%d", &a);
    s[0] = 0;
    s[1] = a;

    for (int i = 2; i <= n; i++) {
        scanf("%d", &a);
        s[i] = a + s[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", s[y] - s[x - 1]);
    }


    return 0;
}