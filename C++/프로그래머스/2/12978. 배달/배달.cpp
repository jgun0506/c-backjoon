#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int inf = 1e9;

vector<int> dist(100);

int solution(int N, vector<vector<int> > road, int K) {
    vector<pii> G[1000];
    fill(dist.begin(), dist.begin()+100, inf);

    for (auto arr : road) {
        int a = arr[0];//마을번호1
        int b = arr[1];//마을번호2
        int c = arr[2];//걸리는 시간

        G[a].push_back({ c,b });
        G[b].push_back({ c,a });
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[1] = 0;//시작점 설정
    pq.push({0,1});
    
    while (!pq.empty()) {
        auto [curtime, curnode] = pq.top();
        pq.pop();
        
        if(dist[curnode]<)
    
}