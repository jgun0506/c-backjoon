#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int n;
int a[1005];
int D[1005];//본인 인덱스 아래에 있는 요소를 더해줌

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    D[1] = 1;
    int temp = a[1];
    for (int i = 2; i <= n; i++) {
        int index = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] > a[j] && D[index] < D[j]) {
                index = j;
            }
        }
        D[i] = D[index] + 1;
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < D[i])
            max = D[i];
    }
    printf("%d", max);
    return 0;
}