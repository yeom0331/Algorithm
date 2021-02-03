#include "lockandkey.h"

void match(int newLock[58][58], vector<vector<int>> key, int rot, int r, int c) {
    int n = key.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(rot==0) {
                newLock[r+i][c+j] += key[i][j];
            }
            else if(rot==1) {
                newLock[r+i][c+j] += key[j][n-1-i];
            }
            else if(rot==2) {
                newLock[r+i][c+j] += key[n-1-j][n-1-i];
            }
            else {
                newLock[r+i][c+j] += key[n-1-j][i];
            }
        }
    }
}

bool check(int newLock[58][58], int offset, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(newLock[offset+i][offset+j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int offset = key.size() - 1;
    for(int r = 0; r < offset + lock.size(); r++) {
        for(int c = 0; c < offset + lock.size(); c++) {
            for(int rot = 0; rot < 4; rot++) { //clock 90
                int newLock[58][58] = {0};
                for(int i=0; i<lock.size(); i++) {
                    for(int j=0; j<lock.size(); j++) {
                        newLock[i + offset][j + offset] = lock[i][j]; //copy lock
                    }
                }
                match(newLock, key, rot, r, c); //match key & lock
                if(check(newLock, offset, lock.size())) {
                    return true;
                }
            }
        }
    }
    return false;
}
