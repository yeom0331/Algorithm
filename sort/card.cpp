#include "sort.h"

static int n, result;
priority_queue<int, vector<int>, greater<int>> pq;

void card() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    while(pq.empty() != 1) {
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();

        int summary = one + two;
        result += summary;
        pq.push(summary);
    }

    cout << result << '\n';
}
