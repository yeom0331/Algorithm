#include <bits/stdc++.h>

using namespace std;

int visited[9], n, m, x, y, result;
vector<int> graph[9];
deque<int> graph_[9];


void ex_stack() {
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(7);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();
    while(!s.empty()) {
        cout << s.top() <<'\n';
        s.pop();
    }
}

void ex_queue() {
    queue<int> q;
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(7);
    q.pop();
    q.push(1);
    q.push(4);
    q.pop();

    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

int ex_factorial_interative(int n) {
    int result = 1;
    for(int i=1; i<=n; i++) {
        result *= i;
    }
    return result;
}

int ex_factorial_recursive(int n) {
    if(n<=1) {
        return 1;
    }
    return n * ex_factorial_recursive(n-1);
}

void adj_matrix() {
    int INF = 9999999;
    int graph[3][3] = {
        {0, 7, 5},
        {7, 0 ,INF},
        {5, INF, 0}
    };

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << graph[i][j] << endl;
        }
    }
}

void adj_list() {
    vector<pair<int, int>> graph[3];

    graph[0].push_back({1, 7});
    graph[0].push_back({2, 5});

    graph[1].push_back({0, 7});

    graph[2].push_back({0, 5});

    for(int i=0; i<3; i++) {
        for(int j=0; j< graph[i].size(); j++) {
            cout << '{' << graph[i][j].first << ',' << graph[i][j].second << '}' << ' ';
        }
        cout << endl;
    }
}



void dfs(int x) {
    visited[x] = true;
    cout << x << ' ';
    for(int i=0; i<graph[x].size(); i++) {
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

void dfs_main() {
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(7);

    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[7].push_back(6);
    graph[7].push_back(8);

    //dfs_self(1);
    dfs(1);
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for(int i=0; i<graph_[x].size(); i++) {
            int y = graph_[x][i];
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

void bfs_main() {
    graph_[1].push_back(2);
    graph_[1].push_back(3);
    graph_[1].push_back(8);

    graph_[2].push_back(1);
    graph_[2].push_back(7);

    graph_[3].push_back(1);
    graph_[3].push_back(4);
    graph_[3].push_back(5);

    graph_[4].push_back(3);
    graph_[4].push_back(5);

    graph_[5].push_back(3);
    graph_[5].push_back(4);

    graph_[6].push_back(7);

    graph_[7].push_back(2);
    graph_[7].push_back(6);
    graph_[7].push_back(8);

    graph_[8].push_back(1);
    graph_[8].push_back(7);

    bfs(1);
}

int graph1[1000][1000];

bool icecream(int x, int y) {
    if(x<=-1 || x >= n || y<=-1 || y>=m) {
        return false;
    }
    if(graph1[x][y]==0) {
        graph1[x][y] = 1;
        icecream(x-1, y);
        icecream(x+1, y);
        icecream(x, y-1);
        icecream(x, y+1);
        return true;
    }
    return false;
}

void A() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &graph1[i][j]);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(icecream(i,j)==true) {
                result++;
            }
        }
    }
    cout << result << endl;
}

int main()
{
    //ex_stack();
    //ex_queue();
    //cout << ex_factorial_interative(5) << endl;
    //cout << ex_factorial_recursive(5) << endl;
    //adj_list();
    //adj_matrix();
    //dfs_main();
    //bfs_main();
    A();
}
