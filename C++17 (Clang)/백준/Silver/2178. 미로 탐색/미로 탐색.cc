#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

char miro[102][102];
int dist[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        cin >> miro[i];
    }

    q.push({ 0,0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            if (miro[nx][ny] == '0' || dist[nx][ny] > 0)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx,ny });
        }
    }
    cout << dist[n - 1][m - 1];

    return 0;
}

