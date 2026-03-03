#include <bits/stdc++.h>

char board[2200][2200];

void func(int k, int x, int y) {
    if (k == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1)
                    board[x + i][y + j] = ' ';
                else
                    board[x + i][y + j] = '*';
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                continue;
            func(k / 3, x + i * k / 3, y + j * k / 3);
        }
    }
}


using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    func(n, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                cout << board[i][j];
            else
                cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}