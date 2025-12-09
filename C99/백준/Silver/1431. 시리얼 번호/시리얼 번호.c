#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

int n;
char str[55][55];

int sum(char a[]) {
    int len = strlen(a);
    int total = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            total += a[i] - '0';
        }
    }

    return total;
}


int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (strlen(str[j]) > strlen(str[j + 1])) {
                char temp[51];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
                continue;
            }
            else if (strlen(str[j]) < strlen(str[j + 1]))
                continue;

            int a_sum = sum(str[j]);
            int b_sum = sum(str[j + 1]);
            if (a_sum > b_sum) {
                char temp[51];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
                continue;
            }
            else if (a_sum < b_sum) 
                continue;

            int a = strlen(str[j]);
            for (int k = 0; k < a; k++) {
                if (str[j][k] > str[j + 1][k]) {
                    char temp[51];
                    strcpy(temp, str[j]);
                    strcpy(str[j], str[j + 1]);
                    strcpy(str[j + 1], temp);
                    break;
                }
                else if (str[j][k] < str[j + 1][k])
                    break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}