#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

#define int long long

using namespace std;

int d[10001];
vector<pair<int, int>> graph[10001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) { // 큐가 비어있지 않다면
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, depand, c;
        cin >> n >> depand >> c;

        fill(d, d+10001, INF);

        for (int j = 0; j < depand; j++) {
            int a, b, s;
            cin >> a >> b >> s;

            graph[b].push_back({a, s});
        }

        dijkstra(c);


        int cnt = 0;
        int answer = 0;
        for (int tmp = 1; tmp <= n+1; tmp++) {
//            cout << d[tmp] << " \n";
            if (d[tmp] == INF) continue;
            if(d[tmp] != INF) cnt++;
            if(answer < d[tmp]) answer = d[tmp];
        }
        cout << cnt << " " << answer << "\n";

    }

    return 0;
}