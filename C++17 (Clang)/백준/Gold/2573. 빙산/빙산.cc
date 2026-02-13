#include <bits/stdc++.h>
#define X first
#define Y second

int board[301][301];
int vis[301][301];//초기화 필요
int around[301][301];//주변에 둘러쌓인 바다의 수(초기화필요)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int year = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> board[i][j];
    }
    while (1) {
        int ice = 0;//빙하갯수
        int count = 0;//대륙의 갯수\
        //vis 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
                around[i][j] = 0;
                if (board[i][j] > 0)
                    ice++;
            }
        }

        if (ice == 0) {
            cout << 0;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0 || vis[i][j] == 1)
                    continue;

                queue<pair<int, int>> Q;
                Q.push({ i,j });
                vis[i][j] = 1;
                count++;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (board[nx][ny] == 0) {
                            around[cur.X][cur.Y]++;
                        }
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0)
                            continue;

                        Q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] -= around[i][j];
                if (board[i][j] < 0)
                    board[i][j] = 0;
            }
        }

        if (count > 1) {
            cout << year;
            return 0;
        }
        year++;
    }
    
    cout << year;

    return 0;
}