#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;

    for(int i=0; i<prices.size(); i++) {
        while(!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        answer[s.top()] = prices.size() - s.top() -1;
        s.pop();
    }
    return answer;
}

/*int main() {
    vector<int> prices;
    int n=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        prices.push_back(x);
    }

    vector<int> result = solution(prices);

    for(int i=0; i<n; i++) {
        cout << result[i] << ' ';
    }
}*/
