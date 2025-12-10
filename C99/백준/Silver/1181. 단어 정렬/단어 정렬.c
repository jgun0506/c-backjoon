#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <ctype.h>

int n;
char arr[20005][51];

int compare(const void* a, const void* b) {
    char* x = (char*)a;
    char* y = (char*)b;
    
    int lenx = strlen(x);
    int leny = strlen(y);
    if (lenx > leny)
        return 1;
    else if (lenx < leny)
        return -1;

    for (int i = 0; i < lenx; i++) {
        if (x[i] > y[i]) {
            return 1;
        }
        else if (x[i] < y[i]) {
            return -1;
        }
    }
    return 0;

}


int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char)*51, compare);


    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i],arr[i+1])!=0)
            printf("%s\n", arr[i]);

    }


    return 0;
}