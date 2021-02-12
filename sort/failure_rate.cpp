#include "sort.h"

int compare(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) return a.first < b.second;
    return a.second > b.second;
}

vector<int> solution(int n, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> v;
    int length = stages.size();
    for(int i=1; i<=n; i++) {
        int cnt = count(stages.begin(), stages.end(), i);
        double failure=0;

        if(length >= 1) {
            failure = (double)cnt / length;
        }
        v.push_back({i,failure});
        length-=cnt;
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++) {
        answer.push_back(v[i].first);
    }

    return answer;
}
