#include "dfs-bfs.h"

class Virus {
public:
    int index;
    int time;
    int x;
    int y;
    Virus(int index, int time, int x, int y) {
        this->index = index;
        this->time = time;
        this->x = x;
        this->y = y;
    }
    bool operator < (Virus &other) {
        return this->index < other.index;
    }
};

static int n, k, graph[201][201];
vector<Virus> v;
static int dx[] = {-1, 0, 1, 0};
static int dy[] = {0, 1, 0, -1};
int target_s, target_x, target_y;

void c_infection() {
    cin >> n >> k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] != 0) {
                v.push_back(Virus(graph[i][j], 0, i, j));
            }
        }
    }

    sort(v.begin(), v.end());

    queue<Virus> q;
    for(int i=0; v.size(); i++) {
        q.push(v[i]);
    }

    cin >> target_s >> target_x >> target_y;

    while(!q.empty()) {
        Virus virus = q.front();
        q.pop();
        if(virus.time == target_s) break;
        for(int i=0; i<4; i++) {
            int nx = virus.x + dx[i];
            int ny = virus.y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if(graph[nx][ny] == 0) {
                    graph[nx][ny] = virus.index;
                    q.push(Virus(virus.index, virus.time+1, nx, ny));
                }
            }
        }
    }

    cout << graph[target_x-1][target_y-1] <<'\n';
}
