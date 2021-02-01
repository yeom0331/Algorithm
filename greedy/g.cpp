#include "g.h"

static int n, m; //coin
vector<int> cointypes;
int balls_wight[11];
static string s;

void g3() {
    cin >> s;
    int count0 = 0;
    int count1 = 0;

    if(s[0] == '1') {
        count0 += 1;
    }
    else {
        count1 += 1;
    }

    for(int i=0; i<s.size()-1; i++) {
        if(s[i] != s[i+1]) {
            if(s[i+1] == '0') {
                count1+=1;
            }
            else {
                count0+=1;
            }
        }
    }

    cout << min(count0, count1) << '\n';
}

void g4() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        cointypes.push_back(x);
    }

    sort(cointypes.begin(), cointypes.end());

    int result = 1;
    for(int i=0; i<n; i++) {
        if(result < cointypes[i]) {
            break;
        }
        result+=cointypes[i];
    }

    cout << result << endl;
}

void g5() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        balls_wight[x] += 1;
    }

    int result = 0;

    for(int i=1; i<=m; i++) {
        n -= balls_wight[i];
        result += balls_wight[i] * n;
    }

    cout << result << endl;
}

int g6(vector<int> food_times, long long k)
{
    int answer = 0;
    return answer;
}

