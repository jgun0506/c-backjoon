#include <bits/stdc++.h>

int bilding[31][31][31];
int vis[31][31][31];
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0 ,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        queue <tuple<int, int, int>> Q;
        int l, r, c;
        cin >> l >> r >> c;

        int bilding[31][31][31];
        int goalx;
        int goaly;
        int goalz;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    vis[i][j][k] = 0;
                }
            }
        }

        if (l == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    char c;
                    cin >> c;
                    if (c == 'S') {
                        Q.push({ j,k,i });
                        vis[i][j][k] = 1;
                    }
                    if (c == 'E') {
                        goalx = j;
                        goaly = k;
                        goalz = i;
                    }
                    bilding[i][j][k] = c;
                }
            }
        }
        bool clear = false;
        while (!Q.empty() && !clear) {

            tuple<int, int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 6; dir++) {
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];

                if (nx == goalx && ny == goaly && nz == goalz) {
                    vis[nz][nx][ny] = vis[get<2>(cur)][get<0>(cur)][get<1>(cur)] + 1;
                    clear = true;
                    break;
                }

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
                    continue;
                if (vis[nz][nx][ny] > 0 || bilding[nz][nx][ny] != '.')
                    continue;
                vis[nz][nx][ny] = vis[get<2>(cur)][get<0>(cur)][get<1>(cur)] + 1;
                Q.push({ nx,ny,nz });
            }
        }
        if (vis[goalz][goalx][goaly] > 0) {
            cout << "Escaped in " << vis[goalz][goalx][goaly] - 1 << " minute(s).\n";
        }
        else {
            cout << "Trapped!\n";
        }

    }
    return 0;
}