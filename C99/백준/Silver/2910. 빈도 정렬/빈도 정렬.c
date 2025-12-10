#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int n, c;
int arr[1001];
int num[1001];
int count_num[1001];
int k = 0;

int in(int a,int k) {
    for (int i = 0; i < k; i++) {
        if (num[i] == a)
            return 1;
    }
    return 0;
}

void swap(int a) {//a,a+1 바꾸기
    int temp = count_num[a];
    count_num[a] = count_num[a + 1];
    count_num[a + 1] = temp;

    temp = num[a];
    num[a] = num[a + 1];
    num[a + 1] = temp;

}
int how_many(int a) {//num안에있는 a의 갯수 리턴
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a == arr[i]) {
            count++;
        }
    }

    return count;
}
int main() {
    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    for (int i = 0; i < n; i++) {
        if (in(arr[i],k) == 1)//만약 arr[i]가 이미등록되잇다면
            continue;
        num[k] = arr[i];
        k++;
    }

    for (int i = 0; i < k; i++) {
        count_num[i] = how_many(num[i]);
     
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k-1-i; j++) {
            if (count_num[j] < count_num[j + 1]) {
                swap(j);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < count_num[i]; j++) {
            printf("%d ", num[i]);
        }
    }

    

    return 0;
}