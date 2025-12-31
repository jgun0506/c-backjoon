#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 선언된 헤더 파일
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>


int main() {
    
    int t, x, y;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &x, &y);
        int distance = y - x;
        int count = 0;
        unsigned long long p = 1;
        int j = 2;

        while (p < distance) {
            p = j * j;
            j++; 
            count++;
            
        }

        long long sym = 0;
        for (int i = 1;; i++) {
            sym += i * 2;
            count++;
            if (sym >= distance)
                break;            
        }
      
        printf("%d\n", count);
    }

    return 0;
}  