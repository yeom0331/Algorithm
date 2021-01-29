#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "make_team.h"
#include "plancitydivision.h"
#include "curriculum.h"

using namespace std;

int v, e, result;
int parent[100001];
vector<pair<int ,pair<int, int>>> edges;
int indegree[100001];
vector<int> graph[100001];

int find_parent(int x) {
    if(x == parent[x]) return x;
    return find_parent(parent[x]);
}

int improved_find_parent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = improved_find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

void simple_each_other() {
    cin >> v >> e;

    for(int i=1; i<=v; i++) {
        parent[i]  = i;
    }

    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        union_parent(a, b);
    }

    cout << "각 원소가 속한 집합: ";
    for(int i=1; i<=v; i++) {
        cout << find_parent(i) << ' ';
    }
    cout << '\n';

    cout << "부모 테이블: ";
    for(int i=1; i<=v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}

void improved_each_other() {
    cin >> v >> e;

    for(int i=1; i<=v; i++) {
        parent[i]  = i;
    }

    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        union_parent(a, b);
    }

    cout << "각 원소가 속한 집합: ";
    for(int i=1; i<=v; i++) {
        cout << improved_find_parent(i) << ' ';
    }
    cout << '\n';

    cout << "부모 테이블: ";
    for(int i=1; i<=v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}

void cycle_each_other() {
    cin >> v >> e;

    for(int i=1; i<=v; i++) {
        parent[i]  = i;
    }

    bool cycle = false;

    for(int i=0 ; i< e; i++) {
        int a, b;
        cin >> a >> b;
        if(find_parent(a) == find_parent(b)) {
            cycle = true;
            break;
        }
        else {
            union_parent(a, b);
        }
    }

    if(cycle) {
        cout << "cycle!" << '\n';
    }
    else {
        cout << "not cycle!" << '\n';
    }
}

void kruscal() {
    cin >> v >> e;

    for(int i=1; i<=v; i++) {
        parent[i] = i;
    }

    for(int i=0; i<e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({cost, {a, b}});
    }

    sort(edges.begin(), edges.end());

    for(int i=0; i<edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(improved_find_parent(a) != improved_find_parent(b)) {
            union_parent(a, b);
            result += cost;
        }
    }

    cout << result << endl;
}

void topology_sort() {
    vector<int> result;
    queue<int> q;

    for(int i=1; i<=v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for(int i=0; i<graph[now].size(); i++) {
            indegree[graph[now][i]] -= 1;
            if(indegree[graph[now][i]]==0) {
                q.push(graph[now][i]);
            }
        }
    }

    for(int i=0; i<result.size(); i++) {
        cout << result[i] << '\n';
    }
}

void topology_main() {
    cin >> v >> e;
    for(int i=0; i<e; i++) {
         int a, b;
         cin >> a >> b;
         graph[a].push_back(b);
         indegree[b] += 1;
    }

    topology_sort();
}

int main()
{
   //simple_each_other();
   //improved_each_other();
   //cycle_each_other();
   //kruscal();
   //topology_main();
   //make_team();
   //city_division();
    curriculum();
}
