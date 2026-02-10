#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MX 1000005                   // 한쪽 여유; 전체는 [base-여유, base+여유) 느낌
static int dat[2*MX + 5];            // 덱 저장소
static char p[100000 + 5];           // 명령어
static char s[400000 + 5];           // 입력 배열 문자열

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        // 1) 입력
        int n;
        scanf("%s", p);
        scanf("%d", &n);
        scanf("%s", s);               // "[...]" 한 줄

        // 2) 덱 인덱스/방향 초기화
        int head = MX, tail = MX;     // [head, tail) 구간 사용
        int dir = 1;                  // 1: 정방향, -1: 역방향
        bool ok = true;

        // 3) 숫자 파싱 (빠르고 안전)
        //    n==0이면 아무 것도 넣지 않음
        if (n > 0) {
            int num = 0;
            bool in_num = false;
            for (int i = 0; s[i]; i++) {
                if (isdigit((unsigned char)s[i])) {
                    num = num * 10 + (s[i] - '0');
                    in_num = true;
                } else if (in_num) {
                    dat[tail++] = num;
                    num = 0;
                    in_num = false;
                }
            }
            if (in_num) dat[tail++] = num; // 숫자로 끝났을 때
        }

        // 4) 명령 처리 (R은 토글만, D는 방향에 따라 삭제)
        for (int i = 0; p[i]; i++) {
            if (p[i] == 'R') {
                dir = -dir;
            } else if (p[i] == 'D') {
                if (head == tail) {   // 비어있음
                    puts("error");
                    ok = false;
                    break;
                }
                if (dir == 1) head++; // 앞에서 삭제
                else          tail--; // 뒤에서 삭제
            }
        }
        if (!ok) continue;

        // 5) 출력
        putchar('[');
        if (dir == 1) {
            for (int i = head; i < tail; i++) {
                if (i > head) putchar(',');
                printf("%d", dat[i]);
            }
        } else {
            for (int i = tail - 1; i >= head; i--) {
                if (i < tail - 1) putchar(',');
                printf("%d", dat[i]);
            }
        }
        puts("]");
    }
    return 0;
}
