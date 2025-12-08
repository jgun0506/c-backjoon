#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

int arr[1000000];
int tmp[1000000];

void marge(int st, int en) {//정렬된 두 배열 재정렬
    int mid = (st + en) / 2;

    int lidx = st;
    int ridx = mid;


    for (int i = 0; i < en - st; i++) {
        if (lidx == mid)
            tmp[i] = arr[ridx++];
        else if (ridx == en)
            tmp[i] = arr[lidx++];

        else if (arr[lidx] <= arr[ridx])
            tmp[i] = arr[ridx++];
        else if (arr[lidx] > arr[ridx])
            tmp[i] = arr[lidx++];
    }

    for (int i = 0; i < en - st; i++) {
        arr[st + i] = tmp[i];
    }
}
void marge_sort(int st, int en) {//st~en-1까지 정렬
    if (en - st == 1) return;
    int mid = (en + st) / 2;

    marge_sort(st, mid);
    marge_sort(mid, en);
    marge(st, en);
}


int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    marge_sort(0, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}