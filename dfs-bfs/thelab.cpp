#include "dfs-bfs.h"
// 0 = empty 1 = wall 2 = virus , dfs
static int n, m, result;
int lab[8][8]; //map
int temp[8][8]; //after spread virus
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void virus(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx <n && ny >= 0 && ny < m) {
            if(temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                virus(nx, ny);
            }
        }
    }
}

int safe_area() {
    int safe = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(temp[i][j] == 0) {
                safe++;
            }
        }
    }
    return safe;
}

void dfs_lab(int wall) {
    if(wall == 3) {
        for(int i = 0; i<n; i++) {
            for(int j=0; j<m; j++) {
                temp[i][j] = lab[i][j];
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(temp[i][j] == 2) {
                    virus(i, j);
                }
            }
        }

        result = max(result, safe_area());
        return;
    }


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(lab[i][j] == 0) {
                lab[i][j] = 1;
                wall += 1;
                dfs_lab(wall);
                lab[i][j] = 0;
                wall -= 1;
            }
        }
    }
}

void thelab() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> lab[i][j];
        }
    }

    dfs_lab(0);



    cout << result << endl;
}
