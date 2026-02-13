#include <bits/stdc++.h>
#define X first
#define Y second

int board[30][30];
int vis[30][30];
int ans[3000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int count = 0;
    queue <pair<int, int>> s;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < n; j++) {
            board[i][j] = a[j] - '0';
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int area = 0;
            if (board[i][j] == 0 || vis[i][j] == 1)
                continue;
            s.push({ i,j });
            vis[i][j] = 1;
            area++;
            while (!s.empty()) {
                pair<int, int> cur = s.front();
                s.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] != 1 || vis[nx][ny] != 0)
                        continue;

                    s.push({ nx,ny });
                    vis[nx][ny] = 1;
                    area++;
                }
            }
            ans[count++] = area;
        }
    }
    cout << count << "\n";

    sort(ans, ans + count);

    for (int i = 0; i < count; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}