#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int day[100005][2];

int compare(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;

    if (x[1] > y[1])
        return 1;
    if (x[1] < y[1])
        return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        day[i][0] += a * 100;
        day[i][0] += b;
        day[i][1] += c * 100;
        day[i][1] += d;
    }

    qsort(day, n, sizeof(day[0]), compare);
    
    int t = 301;//3월 1일이라는뜻
    int flower_count = 0;
    int index = 0;
    bool possible = false;
    while (t < 1201) {
        possible = false;
        for (int i = n-1; i >= 0; i--) {
            if (day[i][0] <= t) {
                if (t == day[i][1]) {
                    flower_count = 0;
                    t = 2000;
                    break;
                }
                possible = true;
                t = day[i][1];
                flower_count++;
                break;
            }
        }
        if (!possible) {
            flower_count = 0;
            break;
        }

    }


    printf("%d", flower_count);
    return 0;
}  