#include "make_team.h"

static int n ,m;
static int parent[100001];

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

void make_team() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int cost, a, b;
        cin >> cost >> a >> b;
        if(cost == 0) {
            unionParent(a, b);
        }
        else if(cost == 1) {
            if(findParent(a) == findParent(b)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
}
