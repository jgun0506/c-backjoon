#include <bits/stdc++.h>

int dist[200005];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    fill(dist, dist + 200004, -1);
    queue <int> Q;
    Q.push(n);
    dist[n] = 0;

    while (dist[k] == -1) {
        int cur = Q.front();
        Q.pop();

        for (int dir : {cur - 1, cur + 1, 2 * cur}) {
            if (dir < 0 || dir > 200000 || dist[dir] != -1)
                continue;
            dist[dir] = dist[cur] + 1;
            Q.push(dir);

        }
    }
    cout << dist[k];

    return 0;
}