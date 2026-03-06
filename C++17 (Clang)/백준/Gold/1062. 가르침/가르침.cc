#include <bits/stdc++.h>
using namespace std;

int n, k;
char voca[51][26];
int alpha[26];
bool isused[26];
int max_voca = 0;


void func(int w,int st) {
    if (w == k) {
        int can_read = 0;
        for(int i = 0; i < n; i++) {
            int len = strlen(voca[i]);
            bool read = true;
            for (int j = 4; j < len - 4; j++) {
                if (!isused[voca[i][j] - 'a']) {
                    read = false;
                    break;
                }
            }
            if (read) {
                can_read++;
            }
        }
        max_voca = max(max_voca, can_read);
        return;
    }


    for (int i = st; i < 26; i++) {
        if (alpha[i] == 1) {
            isused[i] = 1;
            func(w + 1, i + 1);
            isused[i] = 0;
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    if (k <= 4) {
        cout << 0;
        return 0;
    }

    k -= 5;//필수알파벳 제외

    isused['a' - 'a'] = 1;//필수알파벳들
    isused['n' - 'a'] = 1;
    isused['t' - 'a'] = 1;
    isused['i' - 'a'] = 1;
    isused['c' - 'a'] = 1;

    for (int i = 0; i < n; i++) {
        cin >> voca[i];
        int len = strlen(voca[i]);

        for (int j = 4; j < len - 4; j++) {
            if (!isused[voca[i][j] - 'a'])
                alpha[voca[i][j] - 'a'] = 1;//가르칠후보
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 1) count++;
    }

    if (count <= k) {//만약 가르쳐야하는 단어의 갯수가 k보다 작으면
        cout << n;  //모든단어 읽기가능
        return 0;
    }
    func(0, 0);
    
    cout << max_voca;
    return 0;
}

