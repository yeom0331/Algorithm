#include <bits/stdc++.h>

using namespace std;

int n, m, tar;
string target;
vector<string> arr;
vector<int> arr1, arr2;
set<int> s;

int sq_s(int n, string target, vector<string> arr) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i+1;
        }
    }
    return -1;
}

void seq_s() {
    cout << "input the number of target & find target name" << endl;
    cin >> n >> target;

    for(int i=0; i<n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    cout << sq_s(n, target, arr) << endl;
}

int re_bs(vector<int> arr1, int tar, int start, int end) { //recusion
    if(start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if(arr1[mid] == tar) {
        return mid;
    }
    else if(arr1[mid] > tar) {
        return re_bs(arr1, tar, start, mid-1);
    }
    else if(arr1[mid] < tar) {
        return re_bs(arr1, tar, mid+1, end);
    }
    return -1;
}

void re_binary() {
    cin >> n >> tar;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        arr1.push_back(x);
    }

    int result = re_bs(arr1, tar, 0, n-1);
    if(result == -1) {
        printf("not exist\n");
    }
    else {
        cout << result+1 << endl;
    }
}

int rep_bs(vector<int> arr1, int tar, int start, int end) {
    while (start <= end) {
        int mid = (start + end)/ 2;
        if(arr1[mid] == tar) {
            return mid;
        }
        else if(arr1[mid] > tar) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return -1;
}

void rep_binary() {
    cin >> n >> tar;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        arr1.push_back(x);
    }

    int result =  rep_bs(arr1, tar, 0, n-1);
    if(result == -1) {
        printf("not exist\n");
    }
    else {
        cout << result+1 << endl;
    }
}

int bs_find_part(vector<int> arr1, int tar, int start, int end) {
    while(start <= end) {
        int mid = (start+end)/2;
        if(arr1[mid] == tar) {
            return mid;
        }
        else if(arr1[mid] > tar) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    return -1;
}

void find_part() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        arr1.push_back(x);
    }
    sort(arr1.begin(), arr1.end());

    cin >> m;
    for(int i=0; i<m; i++) {
        int y=0;
        cin >> y;
        arr2.push_back(y);
    }

    for(int i=0; i<m; i++) {
        int result = bs_find_part(arr1, arr2[i], 0, n-1);
        if(result == -1) {
            cout << "no" << ' ';
        }
        else {
            cout << "yes" << ' ';
        }
    }
}

void set_find_part() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        s.insert(x);
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int y = 0;
        cin >> y;
        arr2.push_back(y);
    }

    for(int i=0; i<m; i++) {
        if(s.find(arr2[i]) != s.end()) {
            cout << "yes" << ' ';
        }
        else {
            cout << "no" << ' ';
        }
    }
}

void making_ricecake() {
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
        int total = 0; //자른 떡의 양
        int mid = (start + end) / 2;
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

int main()
{
    //seq_s();
    //re_binary();
    //rep_binary();
    //find_part();
    //set_find_part();
    //making_ricecake();
}
