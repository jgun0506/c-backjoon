#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

long long arr[100005];

int compare(const void* a,const void* b) {

    long long x = *(long long*)a;
    long long y = *(long long*)b;
    
    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    return 0;

}


int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(long long), compare);

    long long max_num = arr[0];
    int max_length = 1;
    int length = 1;

    
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] == arr[i]) {
            length++;
            continue;
        }
        else {
            if (max_length < length) {
                max_length = length;
                max_num = arr[i - 1];
            }
            length = 1;
        }
    }

    if (max_length < length) {
        max_length = length;
        max_num = arr[n - 1];
    }

    printf("%lld", max_num);


    return 0;
}