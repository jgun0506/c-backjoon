#include <bits/stdc++.h>

int dist[2000005];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;

    cin >> f >> s >> g >> u >> d;

    fill(dist, dist + 2000005, -1);

    queue <int> q;
    q.push(s);
    dist[s] = 0;

    while (dist[g] == -1 && !q.empty()) {
        int cur = q.front();
        q.pop();

        for (int dir : {cur + u, cur - d}) {
            if (dir <= 0 || dir > f)
                continue;
            if (dist[dir] != -1)
                continue;
            

            q.push(dir);
            dist[dir] = dist[cur] + 1;
        }
    }
    if (dist[g] == -1)
        cout << "use the stairs";
    else
        cout << dist[g];

    return 0;
}