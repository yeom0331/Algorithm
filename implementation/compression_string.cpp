#include "implementation.h"


int solution(string s) {
    int answer = s.size();
    string result = "";
    for(int i=1; i<s.size()/2 + 1; i++) {
        string prev = s.substr(0, i);
        int cnt = 1;
        for(int j=i; j<s.size(); j+=i) {
            if(prev == s.substr(j, i)) {
                cnt+=1;
            }
            else {
                result += (cnt >= 2)? to_string(cnt) + prev : prev;
                prev = s.substr(j,i);
                cnt = 1;
            }
        }
        result += (cnt >=2)? to_string(cnt) + prev : prev;
        answer = min(answer, (int)result.size());
    }
    return answer;
}


void compression_string() {
    string s = "";
    cin >> s;
    cout << solution(s) << endl;
}

