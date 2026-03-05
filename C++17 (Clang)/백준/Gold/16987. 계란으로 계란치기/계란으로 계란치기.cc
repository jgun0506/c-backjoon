#include <bits/stdc++.h>
using namespace std;

int n;
int max_break;
int s[305];
int w[305];

void func(int k) {

    if (k > n) {//오른쪽 끝까지 간 경우
        int break_count = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i] <= 0) 
                break_count++;
        }
        max_break = max(max_break, break_count);
        return;
    }

    if (s[k] <= 0){//깨져잇으면
        func(k + 1);//다음 계란손에들기
        return;
    }
    bool b = 0;
    for (int i = 1; i <= n; i++) {
        if (i == k) {
            continue;
        }
        if (s[i] > 0) {
            b = 1;
            s[i] -= w[k];
            s[k] -= w[i];
            func(k + 1);
            s[i] += w[k];
            s[k] += w[i];
        }
    }
    if (b == 0)//만약 들고잇는 게란밖에 없다면 위의 for문을 돌지못해 k+1을 가지못함
        func(k + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> w[i];
    }

    func(1);

    cout << max_break;

    return 0;
}

