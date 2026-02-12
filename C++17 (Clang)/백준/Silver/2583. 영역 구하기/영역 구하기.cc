#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define X first
#define Y second

int board[102][102];
int vis[102][102];
int dx[4] = { 0,1,0,-1 };//m
int dy[4] = { 1,0,-1,0 };

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    int count = 0;//구역 갯수
    int arr[101];//구역 넓이 저장 해주기
    cin >> m >> n >> k;
    while (k--) {//색깔 채워주기
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = b; i < d; i++) {
            for (int j = a; j < c; j++) {
                board[i][j] = 1;
            }
        }
    }
    queue<pair<int, int>> Q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 || vis[i][j] == 1)
                continue;
            int area = 0;
            Q.push({ i,j });
            vis[i][j] = 1;
            count++;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 0)
                        continue;

                    Q.push({ nx,ny });
                    vis[nx][ny] = 1;
                }

            }
            arr[count - 1] = area;
        }
    }
    cout << count << "\n";
    sort(arr, arr + count);
    for (int i = 0; i < count; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}