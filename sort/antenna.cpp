#include "sort.h"

static int n;
vector<int> home;

void antenna() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int location;
        cin >> location;
        home.push_back(location);
    }
    sort(home.begin(), home.end());

    cout << home[(n-1)/2] << endl;
}
