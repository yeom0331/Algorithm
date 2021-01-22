#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, cnt = 0;
    queue<pair<int, int>> que;
    priority_queue<int> pq;

    for(int i=0; i<priorities.size(); i++) {
        que.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while(!pq.empty()) {
        int index = que.front().first;
        int value = que.front().second;
        que.pop();

        if(pq.top() == value) {
            pq.pop();
            cnt++;
            if(index == location) {
                answer = cnt;
                break;
            }
        }
        else {
            que.push(make_pair(index, value));
        }
    }
    return answer;
}

/*int main() {
    vector<int> priorties;
    int location=0, n=0;
    cin >> n >> location;

    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        priorties.push_back(x);
    }

    cout << solution(priorties, location) << endl;
}*/
