#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for(auto num : numbers) {
        temp.push_back(to_string(num)); //int -> string
    }
    sort(temp.begin(), temp.end(), cmp);
    if(temp.at(0) == "0") return "0";
    for(auto num : temp) {
        answer += num;
    }
    return answer;
}

/*int main() {
    cout << solution({6,10, 20}) << endl;
}*/
