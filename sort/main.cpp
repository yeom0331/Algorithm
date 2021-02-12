#include "sort.h"

using namespace std;

int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void s_sort() { //select sort
    int array[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    for(int i=0; i<10; i++) {
        int min_index = i;
        for(int j=i+1; j<10; j++) {
            if(array[min_index] > array[j]) {
                min_index = j;
            }
        }
        swap(array[i], array[min_index]); //swap
    }

    for(int i=0; i<10; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}


void i_sort() { //insert sort
    int array[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    for(int i=0; i<10; i++) {
        for(int j=i; j > 0; j--) {
            if(array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            }
            else {
                break;
            }
        }
    }

    for(int i=0; i<10; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}


void q_sort(int *arr, int start, int end) { //quick_sort
    if(start >= end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;
    while(left <= right) {
        while (left <= end && arr[left] <= arr[pivot]) left++; // 피벗보다 큰 데이터를 찾을 때까지 반복
        while (right > start && arr[right] >= arr[pivot]) right--; // 피벗보다 큰 데이터를 찾을 때까지 반복
        if(left > right) swap(arr[pivot], arr[right]);
        else {
            swap(arr[left], arr[pivot]);
        }
    }

    q_sort(arr, start, right-1);
    q_sort(arr, right+1, end);
}

void quick_sort() {
    q_sort(arr, 0, 9);
    for(int i=0; i<10; i++) {
        cout << arr[i] << ' ';
    }
}

void c_sort(int *arr) {
    int cnt[10] = {0,};
    for(int i=0; i<10; i++) {
        cnt[arr[i]] += 1;
    }
    for(int i=0; i<10; i++) {
        for(int j=0; j<cnt[i]; j++) {
            cout << i << ' ';
        }
    }
}

int n, k;
vector<int> v;

int rev(int x, int y) {
    return x > y;
}

void top_to_bottom() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), rev);

    for(int i=0; i<n; i++) {
        cout << v[i] << ' ';
    }
}

class student1 {
public:
    string name;
    int score;
    student1(string name, int score) {
        this->name = name;
        this->score = score;
    }

    bool operator < (student1 &other) { // 정렬 기준은 '점수가 낮은 순서'
        return this->score < other.score;
    }
};

vector<student1> s;

void grade() {
    cin >> n;
    for(int i=0; i<n; i++) {
        string name;
        int score;
        cin >> name >> score;
        s.push_back(student1(name, score));
    }
    sort(s.begin(), s.end());

    for(int i=0; i<n; i++) {
        cout << s[i].name << endl;
    }
}

void replace_ab() {
    cin >> n >> k;
    vector<int> a, b;
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0; i<n; i++) {
        int x = 0;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), rev);

    for(int i=0; i<k; i++) {
        if(a[i] < b[i]) {
            swap(a[i], b[i]);
        }
        else break;
    }

    int result = 0;
    for(int i=0; i<n; i++) {
        result += a[i];
    }

    cout << result << endl;
}


int main()
{
    //s_sort();
    //i_sort();
    //quick_sort();
    //c_sort(arr);
    //top_to_bottom();
    //grade();
    //replace_ab();
    //kem();
    //antenna();
    card();
}
