#include "sort.h"

class student {
public:
    string name;
    int k;
    int e;
    int m;
    student(string name, int k, int e, int m) {
        this->name = name;
        this->k = k;
        this->e = e;
        this->m = m;
    }

    bool operator < (student &other) {
        if(this->k == other.k && this->e == other.e && this->m == other.m) {
            return this->name < other.name;
        }
        else if(this->k == other.k && this->e == other.e) {
            return this->m > other.m;
        }
        else if(this->k == other.k) {
            return this->e < other.e;
        }
        return this->k > other.k;
    }
};

static vector<student> v;

void kem() {
    int n = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        string name = "";
        int k, e, m;
        cin >> name >> k >> e >> m;
        v.push_back(student(name, k, e, m));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        cout << v[i].name << '\n';
    }
}
