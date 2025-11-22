#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using std::string;
using std::vector;
using std::cin;
using std::cout;

int N;

void Turn(const vector<int> &A, vector<int> &result) {
    int high = 199;
    while (high >= 0 && A[high] == 0) {
        high--;
    }
    
    for (int i = 0; i <= high; i++) {
        result[i] = A[high - i];
    }
}

void Carry(vector<int> &A) {
    for (int i = 0; i < 199; i++) {
        if (A[i] >= N) {
            A[i + 1] += A[i] / N;
            A[i] %= N;
        }
    }
}

bool Check(const vector<int> &num) {
    int start = 199;
    while (start >= 0 && num[start] == 0) {
        start--;
    }
    
    if (start < 0) return true;
    
    for (int i = 0; i <= start / 2; i++) {
        if (num[i] != num[start - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    vector<int> num(200, 0);
    vector<int> turned(200, 0);

    cin >> N >> s;
    
    int len = s.length();
    for (int i = 0; i < len; i++) {
        char c = s[len - 1 - i];
        if (c >= '0' && c <= '9') {
            num[i] = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            num[i] = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            num[i] = c - 'a' + 10;
        }
    }
    
    if (Check(num)) {
        cout << "STEP=0";
        return 0;
    }

    for (int i = 1; i <= 30; i++) {
        turned.assign(200, 0);
        Turn(num, turned);
        for (int j = 0; j < 200; j++) {
            num[j] += turned[j];
        }
        Carry(num);
        if (Check(num)) {
            cout << "STEP=" << i;
            return 0;
        }
    }

    cout << "Impossible!";
    return 0;
}