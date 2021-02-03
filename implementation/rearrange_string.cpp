#include "rearrange_string.h"

static string s;
static vector<char> result;
int digit;

void rearrange_string() {
    cin >> s;

    for(int i=0; i<s.size(); i++) {
        if(isdigit(s[i])) {
            digit += s[i] - '0';
        }
        else {
            result.push_back(s[i]);
        }
    }

    sort(result.begin(), result.end());

    for(int i=0; i<result.size(); i++) {
        cout << result[i];
    }

    if(digit != 0) cout << digit;
    cout << '\n';
}
