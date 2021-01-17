#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr1;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        arr1.push_back(x);
    }

    int start = 0;
    int end = 1e9;
    int result = 0;

    while(start <= end) {
        long long int total = 0;
        int mid = (start+end)/2;
        for(int i=0; i<n; i++) {
            if(arr1[i] > mid) {
                total += arr1[i] - mid;
            }
        }
        if(total < m) {
            end = mid-1;
        }
        else {
            result = mid;
            start = mid+1;
        }
    }

    cout << result << endl;
}
