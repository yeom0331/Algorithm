#include <iostream>
#include <vector>
#include <algorithm>
#include "g.h"

using namespace std;

int n,m,k,result,cnt;
string s;
vector<int> v;

int descending(int a, int b) {
    return a > b;
}

void A() { //change
    int price=0, cnt=0;
    cin >> price;
    int type[4] = {500, 100, 50, 10};
    for(int i=0; i<4; i++) {
        int coin = type[i];
        cnt += price / coin;
        price %= coin;
    }
    cout << cnt << "\n";
}

void B() { //Law of great numbers
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        int number=0;
        cin >> number;
        v.push_back(number);
    }
    sort(v.begin(), v.end(), descending);
    while(true) {
        for(int i=0; i<k; i++) {
            if(m==0) break;
            result += v[0];
            m-=1;
        }
        if(m==0) break;
        result += v[1];
        m-=1;
    }
    cout << result << '\n';
}

void C() { //numbers card game
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int min_ = 10000;
        for(int j=0; j<m; j++) {
            cin >> k;
            min_ = min(min_, k);
        }
        result = max(result, min_);
    }
    cout << result << '\n';
}

void D() { //until 1
    cin >> n >> k;
    while(true) {
        int m = (n / k) * k;
        result += (n - m);
        n = m;
        if(n<k) break;
        result++;
        n /= k;
    }
    result += (n-1);
    cout << result << '\n';
}

void B_11399() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        v[i] = v[i]+v[i-1];
        result += v[i];
    }
    cout << result << '\n';
}

void B_11047() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), descending);
    for(int i=0; i<n; i++) {
        while(k-v[i] >=0) {
            k-=v[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    //A();
    //B();
    //C();
    //D();
    //B_11399();
    //B_11047();
    g3();
    //g4();
    //g5();
}
