#include <bits/stdc++.h>

int dist[200005];
int ans[200005];
int root[200005];
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    fill(dist, dist + 200000, -1);
    queue <int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int dir : {cur - 1, cur + 1, cur * 2}) {
            if (dir < 0 || dir>100000 || dist[dir] != -1)
                continue;
            dist[dir] = dist[cur] + 1;
            ans[dir] = cur;
            q.push(dir);
        }
    }

    cout << dist[k] << "\n";

    int i = dist[k];
    int m = i;
    while (i >= 0) {
        root[i] = k;
        k = ans[k];
        i--;
    }

    for (int j = 0; j <= m; j++) {
        cout << root[j] << ' ';
    }

    return 0;
}