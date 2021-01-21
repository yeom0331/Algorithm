#include <bits/stdc++.h>

using namespace std;

long long top_down_fibo(int x) {
    long long d[100] = {0, };
    if(x==1||x==2) {
        return 1;
    }
    if(d[x] != 0) {
        return d[x];
    }
    d[x] = top_down_fibo(x-1) + top_down_fibo(x-2);
    return d[x];
}

long long bottom_up_fibo() {
    long long d[100] = {0,};
    d[1] = 1;
    d[2] = 1;
    int x = 50;

    for(int i=3; i<=x; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[x] << endl;
    return d[x];
}

void make_1() {
    int d[30000] = {0,};
    int x = 0;
    cin >> x;
    for(int i=2; i<=x; i++) {
        d[i] = d[i-1]+1;
        if(i % 2 == 0) {
            d[i] = min(d[i], d[i/2]+1);
        }
        if(i % 3 == 0) {
            d[i] = min(d[i], d[i/3]+1);
        }
        if(i % 5 == 0) {
            d[i] = min(d[i], d[i/5]+1);
        }
    }
    cout << d[x] << endl;
}

int n, m;
int d[100];
vector<int> food;
vector<int> cash;

void ant_worrior() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        food.push_back(x);
    }

    d[0] = food[0];
    d[1] = max(food[0], food[1]);
    for(int i=2; i<n; i++) {
        d[i] = max(d[i-1], d[i-2] + food[i]);
    }
    cout << d[n-1] << endl;
}

void floor_construction() {
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for(int i=3; i<=n; i++) {
        d[i] = (d[i-1] + d[i-2] * 2) % 796796;
    }
    cout << d[n] << endl;
}

void monetary_composion() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        cash.push_back(x);
    }

    vector<int> index(m+1, 10001);

    index[0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=cash[i]; j<=m; j++) {
            if(index[j-cash[i]]!=10001) {
                index[j] = min(index[j], index[j-cash[i]]+1);
            }
        }
    }
    if(index[m] == 10001) {
        cout << -1 << endl;
    }
    else {
        cout << index[m] << endl;
    }
}

int main()
{
    //cout << top_down_fibo(50) << endl;
    //bottom_up_fibo();
    //make_1();
    //ant_worrior();
    //floor_construction();
    //monetary_composion();
}
