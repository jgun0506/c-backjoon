#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int line[1000005][2];

int mx(int a, int b) {
    return a > b ? a : b;
}

int compare(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    
    if (x[0] > y[0])
        return 1;
    if (x[0] < y[0])
        return -1;
    if (x[1] > y[1])
        return 1;
    if (x[1] < y[1])
        return -1;
    return 0;
}


int main() {
    
    int n;
    int x, y;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &line[i][0], &line[i][1]);
    }
    qsort(line, n, sizeof(line[0]), compare);
    
    int start = line[0][0];
    int end = line[0][1];
    int total = 0;


    for (int i = 1; i < n; i++) {
        if (line[i][0] <= end) {
            end = mx(end, line[i][1]);
        }
        if (line[i][0] > end) {
            total += end - start;
            start = line[i][0];
            end = line[i][1];
        }
    }
    total += end - start;
    
    printf("%d", total);

    return 0;
}  