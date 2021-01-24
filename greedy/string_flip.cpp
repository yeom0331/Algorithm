#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;

    int count0 = 0;
    int count1 = 0;

    if(s[0] == '1') {
        count0++;
    }
    else {
        count1++;
    }

    for(int i=1; i<s.size(); i++) {
        if(s[i]!=s[i+1]) {
            if(s[i+1]=='1') {
                count0++;
            }
            else {
                count1++;
            }
        }
    }

    cout << min(count0, count1) << endl;
}
