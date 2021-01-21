#include <bits/stdc++.h>

using namespace std;

int delivery_sugar(int n) {
    if(n<3||n>5000) return -1;
    int quotient = n/5;

    while(quotient>=0) {
        int temp = n-(quotient*5);
        if(temp % 3 == 0) {
            return quotient + (temp/3);
        }
        quotient--;
    }
    return -1;
}

int main() {
    int n = 0;
    cin >> n;
    cout << delivery_sugar(n) << endl;
}
