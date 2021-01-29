#include "plancitydivision.h"

static int n, m, result;
static int parent[100001];
vector<pair<int, pair<int, int>>> cost;

int fp(int x) {
    if(x==parent[x]) return x;
    return parent[x] = fp(parent[x]);
}

void unionp(int a, int b) {
    a = fp(a);
    b = fp(b);
    if(a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

void city_division() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost.push_back({c, {a,b}});
    }

    sort(cost.begin(), cost.end());
    int big = 0;

    for(int i=0; i<cost.size(); i++) {
        int cost_ = cost[i].first;
        int a = cost[i].second.first;
        int b = cost[i].second.second;
        if(fp(a) != fp(b)) {
            unionp(a, b);
            result += cost_;
            big = cost_;
        }
    }

    cout << result - big << '\n';
}
