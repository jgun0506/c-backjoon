#include <bits/stdc++.h>

char board[1001][1001];
int dist[1001][1001][11];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 });
    dist[0][0][0] = 1;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nk = get<2>(cur);//벽 부순 횟수

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny][nk] > 0)
                continue;
            
            if (board[nx][ny] == '1') {//장애물 만난경우
                //부수기
                if (nk < k) {//더 부술수 잇다면
                    q.push({ nx,ny,nk + 1 });//부수기
                    dist[nx][ny][nk + 1] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                    continue;
                }
                else //더 부술수 없다면
                    continue;
            }
            q.push({ nx,ny,nk});
            dist[nx][ny][nk] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }

    int ans = 999999;

    for (int i = 0; i <= k; i++) {
        if (dist[n - 1][m - 1][i] != 0)
            ans = min(ans, dist[n - 1][m - 1][i]);
    }

    if (ans != 999999)
        cout << ans;
    else
        cout << -1;
    
    return 0;
}