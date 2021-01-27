#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, start; //노드, 간선, 시작 노드
vector<pair<int, int>> graph[100001]; //각 노드에 연결되어 있는 노드에 대한 정보
bool visited[100001];
int d[100001]; //최단 거리 테이블
int graph1[501][501];
int graph2[101][101];
vector<pair<int, int>> graph3[30001];
int d1[30001];

int getsmallestnode() {
    int min_value = INF;
    int index=0; //가장 최단 거리가 짧은 노드
    for(int i=1; i<=n; i++) {
        if(d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void simple_dijkstra(int start) {
    d[start] = 0;
    visited[start] = true;
    for(int j=0; j<graph[start].size(); j++) {
        d[graph[start][j].first] = graph[start][j].second;
    }

    for(int i=0; i<n-1; i++) {
        int now = getsmallestnode();
        visited[now] = true;

        for(int j=0; j<graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            if(cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

void simple_dijkstra_main() {
    cin >> n >> m >> start;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    fill_n(d,100001, INF);
    simple_dijkstra(start);

    for(int i=1; i<=n; i++) {
        if(d[i] == INF) {
            cout << "INFINITY" << endl;
        }
        else {
            cout << d[i] << endl;
        }
    }
}

void improved_dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start]=0;
    while(!pq.empty()) {
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();

        if(d[now] < dist) continue; // 현재 노드가 이미 처리된 적이 있는 노드라면 무시

        for(int i=0; i<graph[now].size(); i++) { // 현재 노드와 연결된 다른 인접한 노드들을 확인
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]) { // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

void improved_dijkstra_main() {
    cin >> n >> m >> start;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    fill(d, d+100001,INF);
    improved_dijkstra(start);

    for(int i=1; i<=n; i++) {
        if(d[i] == INF) {
            cout << "INFINITY" << endl;
        }
        else {
            cout << d[i] << endl;
        }
    }
}

void floyd() {
    cin >> n >> m;
    for(int i=0; i<501; i++) {
        fill(graph1[i], graph1[i]+501, INF);
    }

    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++) {
            if(a==b) graph1[a][b] = 0;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph1[a][b] = c;
    }

    for(int k=1; k<=n; k++) {
        for(int a=1; a<=n; a++) {
            for(int b=1; b<=n; b++) {
                graph1[a][b] = min(graph1[a][b], graph1[a][k] + graph1[k][b]);
            }
        }
    }

    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++) {
            if(graph1[a][b] == INF) {
                cout << "INFINITY" << ' ';
            }
            else {
                cout << graph1[a][b] << ' ';
            }
        }
        cout << '\n';
    }
}

void future_city() {
    cin >> n >> m;

    for(int i=0; i<101; i++) {
        fill(graph2[i], graph2[i]+101, INF);
    }

    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++) {
            if(a == b) graph2[a][b] = 0;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph2[a][b] = 1;
        graph2[b][a] = 1;
    }

    for(int k=1; k<=n; k++) {
        for(int a=1; a<=n; a++) {
            for(int b=1; b<=n; b++) {
                graph2[a][b] = min(graph2[a][b], graph2[a][k]+graph2[k][b]);
            }
        }
    }


    int x=0, k=0;
    cin >> x >> k;

    int result = graph2[1][k] + graph2[k][x];

    if(result >= INF) {
        cout << "-1" << endl;
    }
    else {
        cout << result << endl;
    }
}


void telegram_dijkstra(int start) {
    priority_queue<pair<int ,int>> pq;
    pq.push({0, start});
    d1[start]=0;
    while(!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d1[now] < dist) continue;

        for(int i=0; i<graph3[now].size(); i++) {
            int cost = dist + graph3[now][i].second;
            if(cost < d1[graph3[now][i].first]) {
                d1[graph3[now][i].first] = cost;
                pq.push(make_pair(-cost, graph3[now][i].first));
            }
        }
    }
}

void telegram() {
    cin >> n >> m >> start;
    fill(d1, d1+30001, INF);
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph3[x].push_back({y,z});
    }
    telegram_dijkstra(start);

    int result = 0, max_distance = 0;
    for(int i=1; i<=n; i++) {
        if(d1[i] != INF) {
            result++;
            max_distance = max(max_distance, d1[i]);
        }
    }
    cout << result - 1 << ' ' << max_distance << endl;
}

int main()
{
    //simple_dijkstra_main();
    //improved_dijkstra_main();
    //floyd();
    //future_city();
    telegram();
}
