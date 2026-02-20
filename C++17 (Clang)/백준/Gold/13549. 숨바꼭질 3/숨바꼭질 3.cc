#include <bits/stdc++.h>

int dist[200005];

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    fill(dist, dist + 200004, 100000);
    
    queue <int> Q;
    Q.push(n);
    dist[n] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for (int dir : {cur - 1, cur + 1, 2 * cur}) {

            if (dir < 0 || dir > 200000 || dist[dir] <= dist[cur])
                //dist[dir] <= dist[cur] 의 의미: 
                // dist[dir],dist[cur] 둘다 방문한적이 있는데 만약 dist[dir]>dist[cur] 이면 최솟값을 만들어줄때 필요없는 계산이기에 스킵
                continue;
            if (dir == 2 * cur) {
                dist[dir] = dist[cur];
                Q.push(dir);
                continue;
            }
            dist[dir] = dist[cur] + 1;
            Q.push(dir);
        }
    }
    cout << dist[k];
    return 0;
}
