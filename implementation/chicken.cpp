#include "implementation.h"

static int n, m;
vector<pair<int, int>> chicken_;
vector<pair<int, int>> house;
int city[51][51]; //map

int get_sum(vector<pair<int, int>> chicken_c) {
    int result = 0;
    for(int i=0; i<house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        int temp = 1e9;
        for(int j=0; j<chicken_c.size(); j++) {
            int cx = chicken_c[j].first;
            int cy = chicken_c[j].second;
            temp = min(temp, abs(hx - cx) + abs(hy - cy));
        }
        result += temp;
    }
    return result;
}

void chicken() {
    cin >> n >> m;
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            cin >> city[r][c];
            if(city[r][c] == 1) house.push_back({r,c});
            else if(city[r][c] == 2) chicken_.push_back({r,c});
        }
    }

    vector<bool> binary(chicken_.size());
    fill(binary.end() - m, binary.end(), true);

    int result = 1e9;

    do {
        vector<pair<int, int>> now;
        for(int i=0; i<chicken_.size(); i++) {
            if(binary[i]) {
                int cx = chicken_[i].first;
                int cy = chicken_[i].second;
                now.push_back({cx, cy});
            }
        }
        result = min(result, get_sum(now));
    }while(next_permutation(binary.begin(), binary.end()));

    cout << result << endl;

}
