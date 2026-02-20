#include <bits/stdc++.h>
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int board[101][101];
int dis[101][101];//거리정보
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count = 1;//대륙의 갯수
    int n;
    cin >> n;
    int min = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    queue <pair<int, int>> Q;
    for (int i = 0; i < n; i++) {//대륙의 번호 부과하기
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || dis[i][j] > 0)
                continue;

            Q.push({ i,j });
            dis[i][j] = 1;
            board[i][j] = count;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] == 0 || dis[nx][ny] > 0)
                        continue;

                    Q.push({ nx,ny });
                    dis[nx][ny] = 1;
                    board[nx][ny] = count;
                }
            }
            count++;
        }
    }

  
    for (int i = 0; i < n; i++) {
        fill(dis[i], dis[i] + n, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0)
                continue;

            for (int o = 0; o < n; o++) {
                fill(dis[o], dis[o] + n, 0);
            }

            queue <pair<int, int>> Q;
            int ground = board[i][j];//무슨땅인가
            Q.push({ i,j });
            dis[i][j] = 1;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] == ground || dis[nx][ny] > 0)
                        continue;//현재 밟고잇는 땅이면 스킵 
                    Q.push({ nx,ny });
                    dis[nx][ny] = dis[cur.X][cur.Y] + 1;
                }
            }
            for (int k = 0; k < n; k++) {
                for (int m = 0; m < n; m++) {
                    if (board[k][m] == ground || board[k][m] == 0 || dis[k][m] == 0)
                        continue;
                    if (min > dis[k][m]) {
                        min = dis[k][m];
                    }
                }
            }
        }
    }
    
    cout << min - 2;
    return 0;
}