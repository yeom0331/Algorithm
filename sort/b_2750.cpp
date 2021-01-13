#include <bits/stdc++.h>

using namespace  std;

int n;
vector<int> v;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        cout << v[i] << endl;
    }
}
