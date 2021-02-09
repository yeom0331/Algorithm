#include "dfs-bfs.h"

int balanced_string(string p) {
    int count = 0; //left
    for(int i=0; i<p.size(); i++) {
        if(p[i] =='(') count += 1;
        else count -= 1;
        if(count == 0) return i;
    }
    return -1;
}

bool checkproper(string p) {
    int count = 0;
    for(int i=0; i<p.size(); i++) {
        if(p[i] == '(') count+=1;
        else {
            if(count==0) {
                return false;
            }
            count-=1;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if(p=="") return answer;
    int index = balanced_string(p);
    string u = p.substr(0, index+1);
    string v = p.substr(index+1);

    if(checkproper(u)) {
        answer = u + solution(v);
    }
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2);
        for(int i=0; i<u.size(); i++) {
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}

void change_bracket() {
    string w = "";
    cin >> w;
    cout << solution(w) << '\n';
}
