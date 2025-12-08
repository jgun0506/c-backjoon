#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

/*계수정렬 활용*/

int arr[10001] = { 0, };

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        arr[a]++;
    }

    for (int i = 0; i < 10001; i++) {
        if (arr[i] == 0)
            continue;
        int k = arr[i];

        for (int j = 0; j < k; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}