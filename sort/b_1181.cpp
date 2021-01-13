#include <bits/stdc++.h>

using namespace  std;

int n;
vector<string> v;

int compare(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;
    }
    else {
        return a.size() < b.size();
    }
}

int main() {
    cin >> n;
    string overlap;
    for(int i=0; i<n; i++) {
        string word;
        cin >> word;
        v.push_back(word);
    }
    sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++) {
        if(overlap==v[i]) continue;
        cout << v[i] << '\n';
        overlap=v[i];
    }
}
