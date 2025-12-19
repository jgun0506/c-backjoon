#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

int plugin[102];//현재 꽂혀잇는 플러그 배열
int plug[102];
int n, k;
int distance[102];

bool isin(int a) {//a가 plugin 에 포함되있으면 true
    for (int i = 0; i < n; i++) {
        if (plugin[i] == a)
            return true;
    }
    return false;
}


int main() {
    

    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < k; i++) {
        scanf("%d", &plug[i]);
    }

    int index = 0;
    int in = 0;
    while (index < n) {
        if (isin(plug[in])) {
            in++;
            continue;
        }
        else {
            plugin[index] = plug[in];
            index++;
            in++;
        }
    }

    int pop_count = 0;

    for (int i = n; i < k; i++) {
        if (isin(plug[i])) {//plug[i]가 plugin에 있는지 확인하는 함수
            continue;
        }
        else {
            memset(distance, 0, sizeof(int) * n);
            for (int j = 0; j < n; j++) {
                for (int m = i + 1; m < k; m++) {
                    if (plugin[j] == plug[m]) {
                        distance[j] = m;
                        break;
                    }
                }
            }
            int min = 0;
            int min_index = 0;
            for (int j = 0; j < n; j++) {
                if (min < distance[j]) {
                    min = distance[j];
                    min_index = j;
                }
                if (distance[j] == 0) {
                    min_index = j;
                    break;
                }
            }
            plugin[min_index] = plug[i];
            pop_count++;
        }
    }

    printf("%d", pop_count);
    

    return 0;
}  