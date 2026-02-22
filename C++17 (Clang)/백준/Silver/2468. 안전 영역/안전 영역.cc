#include <bits/stdc++.h>
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int board[105][105];
int vis[105][105];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int max_safe = 1;
    int safe = 1;//적어도 1이상
    int water_level = 1;

    while (safe != 0) {//완전히 잠기지 않을 동안
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }
        safe = 0;
        for (int i = 0; i < n; i++) {//땅찾기
            for (int j = 0; j < n; j++) {
                if (board[i][j] <= water_level || vis[i][j] == 1)
                    continue;
                queue <pair<int, int>> q;
                q.push({ i,j });
                vis[i][j] = 1;
                safe++;
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] <= water_level)
                            continue;

                        q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        water_level++;

        if (max_safe < safe)
            max_safe = safe;
    }
    cout << max_safe;

    return 0;
}