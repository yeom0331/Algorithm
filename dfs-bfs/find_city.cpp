#include "dfs-bfs.h"

static int n, m, k, x;
static vector<int> graph[300001];
static vector<int> d(300001, -1);

void find_city() {
    cin >> n >> m >> k >> x;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    d[x] = 0;

    queue<int> q;
    q.push(x);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i=0; i<graph[now].size(); i++) {
            int nextnode = graph[now][i];
            if(d[nextnode] == -1) {
                d[nextnode] = d[now] + 1;
                q.push(nextnode);
            }
        }
    }


    bool check = false;

    for(int i=1; i<=n; i++) {
        if(d[i] == k) {
            cout << i << '\n';
            check = true;
        }
    }

    if(!check) cout << "-1\n";
}
