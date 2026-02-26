#include <bits/stdc++.h>

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1002][1002];
int dist[1002][1002][10];//본인 방문 여부
int vis[1002][1002];

int s[10];//범위

int ans[10];//각 성의 갯수

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    queue <pair<int, int>> e;
    queue <tuple<int, int, int>> q[10];
    //시작점 큐에 넣어주기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.' || board[i][j] == '#') {
                continue;
            }
            e.push({ i,j });
            q[board[i][j] - '0'].push({ i,j,0 });
            dist[i][j][board[i][j] - '0'] = 1;
            ans[board[i][j] - '0']++;
            vis[i][j] = 1;
        }
    }
    int dot = 0;
    int castle = 0;
    while (!e.empty()) {
        auto [x_cur, y_cur] = e.front();
        e.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x_cur + dx[dir];
            int ny = y_cur + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '#' || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            dot++;
            e.push({ nx,ny });
        }
    }
    int round = 0;
    while (dot > castle) {//모든 빈칸이 성으로 점령당할때 까지

        round++;
        for (int i = 1; i <= p; i++) {
            while (!q[i].empty() && get<2>(q[i].front()) < s[i] * round) {
                auto [x_cur, y_cur, s_cur] = q[i].front();
                q[i].pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x_cur + dx[dir];
                    int ny = y_cur + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (board[nx][ny] == '#')
                        continue;
                    if (board[nx][ny] != '.' && board[nx][ny] != board[x_cur][y_cur])
                        continue;

                    //빈공간 이거나 자기 자신이 점령한 땅
                    if (board[nx][ny] == board[x_cur][y_cur]) {//점령햇던땅
                        if (dist[nx][ny][i] <= dist[x_cur][y_cur][i] + 1)
                            continue;
                        dist[nx][ny][i] = dist[x_cur][y_cur][i] + 1;
                        q[i].push({ nx,ny,s_cur + 1 });
                    }
                    else {//빈땅이라면
                        board[nx][ny] = board[x_cur][y_cur];
                        dist[nx][ny][i] = dist[x_cur][y_cur][i] + 1;
                        q[i].push({ nx,ny,s_cur + 1 });
                        ans[i]++;
                        castle++;
                    }
                }
            }
        }
    }


    for (int i = 1; i <= p; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}