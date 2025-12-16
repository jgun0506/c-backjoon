#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int T[100005][2];
int n;

int compare(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;

    if (x[1] > y[1])
        return 1;
    if (x[1] < y[1])
        return -1;
    if (x[0] > y[0])
        return 1;
    if (x[0] < y[0])
        return -1;
    return 0;
}


int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &T[i][0], &T[i][1]);//0:시작,1:종료
    }
    
    qsort(T, n, sizeof(T[0]), compare);

    int count = 1;
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (T[index][1] <= T[i][0]) {
            count++;
            index = i;
        }
    }
   
    printf("%d", count);
    

    return 0;
}  