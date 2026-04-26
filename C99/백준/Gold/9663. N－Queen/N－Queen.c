#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:28388608")   // 8MB 스택메모리늘려줌
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

int n;
int arr[15][15];
int count;
bool isused1[15];
bool isused2[40];
bool isused3[40];




void func(int k) {
    if (n == k) {
        count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isused1[i] && !isused2[i + k] && !isused3[n - 1 + k - i]) {
            isused1[i] = 1;
            isused2[i + k] = 1;
            isused3[n - 1 + k - i] = 1;
            func(k + 1);
            isused1[i] = 0;
            isused2[i + k] = 0;
            isused3[n - 1 + k - i] = 0;
        }
    }
}


int main()
{

    scanf("%d", &n);

    func(0);
    printf("%d", count);
    return 0;
}
