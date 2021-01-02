#include <bits/stdc++.h>

using namespace std;

int n, cnt;
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


int main()
{
    //A();
    B();
}
