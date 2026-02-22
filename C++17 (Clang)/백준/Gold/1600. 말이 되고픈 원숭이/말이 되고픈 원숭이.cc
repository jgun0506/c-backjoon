#include <bits/stdc++.h>

int dx[12] = { 1,0,-1,0,1,2,2,1,-1,-2,-2,-1 };
int dy[12] = { 0,1,0,-1,2,1,-1,-2,-2,-1,1,2 };
int board[205][205];
int dist[201][201][31];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, w, h;
    cin >> k;
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 });
    dist[0][0][0] = 1;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 12; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nk = get<2>(cur);//말스텝 이용 횟수
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (dist[nx][ny][nk] > 0 || board[nx][ny] == 1)
                continue;
                
            if (dir >= 4) {//말스텝을 할경우
                if (nk >= k || dist[nx][ny][nk + 1] > 0)//말스텝 다써버린경우
                    continue;
                q.push({ nx,ny,nk + 1 });
                dist[nx][ny][nk + 1] = dist[get<0>(cur)][get<1>(cur)][nk] + 1;
            }       
            else {//상하좌우 이동할경우
                q.push({ nx,ny,nk });
                dist[nx][ny][nk] = dist[get<0>(cur)][get<1>(cur)][nk] + 1;
            }
        }
    }
    int ans = 9999999;
    for (int i = 0; i <= k; i++) {
        if (dist[h - 1][w - 1][i] != 0) {
            ans = min(ans, dist[h - 1][w - 1][i] - 1);
        }
    }
    if (ans == 9999999)
        cout << -1;
    else
        cout << ans;

    return 0;
}