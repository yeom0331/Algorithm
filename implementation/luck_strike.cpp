#include "luck_strike.h"

static int n;


void luck_strike() {
    cin >> n;
    string s = to_string(n);
    int s_halfsize = s.size() / 2;

    int left = 0;
    int right = 0;

    for(int i=0; i<s_halfsize; i++) {
        left += s[i];
    }

    for(int i=s_halfsize; i<s.size(); i++) {
        right += s[i];
    }

    if(left == right) {
        cout << "LUCKY" << endl;
    }
    else {
        cout << "READY" << endl;
    }
}
