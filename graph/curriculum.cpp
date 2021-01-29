#include "curriculum.h"

static int v=0;
static int indegree[501];
int times[501];
static vector<int> graph[501];

void cc() {
    vector<int> result(501);
    queue<int> q;

    for(int i=1; i<=v; i++) {
        result[i] = times[i];
    }

    for(int i=1; i<=v; i++) {
        if(indegree[i] == 0)  {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<graph[now].size(); i++) {
            result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
            indegree[graph[now][i]] -= 1;
            if(indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]);
            }
        }
    }

    for(int i=1; i<=v; i++) {
        cout << result[i] << '\n';
    }
}

void curriculum() {
    cin >> v;
    for(int i=1; i<=v; i++) {
        int x;
        cin >> x;
        times[i] = x;
        while(true) {
            cin >> x;
            if(x==-1) break;
            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }

    cc();
}
