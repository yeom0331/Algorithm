#include "implementation.h"

static int n, k, l;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};

int snake_map[101][101];
vector<pair<int, char>> info;

int turn(int direction, char c) {
    if (c == 'L') direction = (direction == 0)? 3 : direction - 1;
    else direction = (direction + 1) % 4;
    return direction;
}

int quicksort() {
   int x = 1, y = 1; //first snake head location
   int time = 0;
   snake_map[x][y] = 2; //current snake location
   int direction = 0; //first east
   int index = 0;
   queue<pair<int, int>> q; //snake location info(tail's on front)
   q.push({x,y});

   while(true) {
       int nx = x + dx[direction];
       int ny = y + dy[direction];

       if(1<=nx && nx <=n && 1<=ny && ny<= n && snake_map[nx][ny] != 2) {
           if(snake_map[nx][ny] == 0) { //not apple
               snake_map[nx][ny] = 2;
               q.push({nx, ny});
               int px = q.front().first;
               int py = q.front().second;
               q.pop();
               snake_map[px][py] = 0;
           }

           if(snake_map[nx][ny] == 1) {
               snake_map[nx][ny] = 2;
               q.push({nx, ny});
           }
       }
       //crush on wall or body
       else {
           time+=1;
           break;
       }

       x = nx;
       y = ny;
       time += 1;
       if(index < l && time == info[index].first) { //turning time
           direction = turn(direction, info[index].second);
           index+=1;
       }
   }
   return time;
}


void snake() {
    cin >> n >> k;

    //apple
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        snake_map[x][y] = 1;
    }

    cin >> l;
    for(int i=0; i<l; i++) {
        int x;
        char c;
        cin >> x >> c;
        info.push_back({x,c});
    }

    cout << quicksort() << endl;
}
