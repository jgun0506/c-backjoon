#include <bits/stdc++.h>

char board[7000][7000];

void func(int k, int x, int y) {//(x,y):왼쪽 모서리 좌표
    if (k == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 1 && j % 2 == 0)
                    continue;
                if (i == 2 && j != 2)
                    continue;
                board[x - i][y + j] = '*';
            }
        }
        return;
    }

    func(k / 2, x, y);
    func(k / 2, x - k / 2, y +  k / 2);
    func(k / 2, x, y + k );
}


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    //n: 높이
    for (int i = 0; i < n; i++)
        fill(board[i], board[i] + 2 * n + 2, ' ');
    
    func(n, n - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}

