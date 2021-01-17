#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr1;
set<int> s;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        s.insert(x);
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int y = 0;
        cin >> y;
        arr1.push_back(y);
    }

    for(int i=0; i<m; i++) {
        if(s.find(arr1[i])!=s.end()) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}
