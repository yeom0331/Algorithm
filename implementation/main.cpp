#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, cnt, result, direction;
string s;

void A() { //UDLR -> simulation
    cin >> n;
    cin.ignore();
    int x=1, y=1;
    int mx[4] = {0,0,-1,1};
    int my[4] = {-1,1,0,0};
    string move = {'L', 'R', 'U', 'D'};
    getline(cin, s);
    for(int i=0; i<s.length(); i++) {
        char plan = s[i];
        int nx=0, ny=0;
        for(int j=0; j<4; j++) {
            if(plan == move[j]) {
                nx = x+mx[j];
                ny = y+my[j];
            }
        }
        if(nx<1 || ny<1 || nx>n || ny>n) continue;
        x = nx;
        y = ny;
    }
    cout << x << ' ' << y << '\n';
}

bool check(int h, int m, int s) {
    if(h % 10 == 3 || m % 10 == 3 || m / 10 == 3 || s % 10 == 3 || s / 10 == 3) {
        return true;
    }
    else return false;
}
void B() { //CLOCK -> full search
    cin >> n;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<60; j++) {
            for(int k=0; k<60; k++) {
                if (check(i,j,k)==true) cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

void C() {  //Royal knight
    cin >> s;
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1 ,1};
    int row = s[1] - '0';
    int line = s[0] - 'a' + 1;

    for(int i=0; i<8; i++) {
        int nr = row + dx[i];
        int nl = line + dy[i];
        if(nr >= 1 && nr <= 8 && nl >= 1 && nl <= 8) {
            result++;
        }
    }
    cout << result << '\n';
}

void left() {
    direction -= 1;
    if(direction == -1) {
        direction = 3;
    }
}

void D() { //game development
    int d[50][50];
    int map[50][50];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int turn=0;

    cin >> n >> m;
    cin >> x >> y >> direction;

    d[x][y] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int k;
            cin >> k;
            map[i][j] = k;
        }
    }

    cnt = 1;
    while(true) {
        left();
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(d[nx][ny] == 0 && map[nx][ny] == 0) {
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt++;
            turn = 0;
            continue;
        }
        else {
            turn++;
        }

        if(turn == 4) {
            nx = x - dx[direction];
            ny = y - dy[direction];
            if(map[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            else {
                break;
            }
            turn = 0;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    //A();
    //B();
    //C();
    D();
}
