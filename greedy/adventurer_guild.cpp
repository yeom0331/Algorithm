#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> fear;

int ad_guild() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        fear.push_back(x);
    }
    sort(fear.begin(), fear.end());

    int cnt=0;
    int result=0;

    for(int i=0; i<n; i++) {
        cnt++;
        if(cnt >= fear[i]) {
            result++;
            cnt=0;
        }
    }
    cout << result << endl;
}
