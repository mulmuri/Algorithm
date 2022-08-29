#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int SIZE = 101;



int r,c;
string arr[SIZE];

void solve(int tc) {
    cin >> r >> c;

    for (int i=0; i<r; i++) cin >> arr[i];

    bool flag = 0;
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) if (arr[i][j] == '^') flag = 1;

    if (flag == 0) {
        cout << "Case #" << tc << ": ";
        cout << "Possible" << endl;
        for (int i=0; i<r; i++) cout << arr[i] << endl;
        return;
    }

    if (r == 1 || c == 1) {
        cout << "Case #" << tc << ": ";
        cout << "Impossible" << endl;
        return;
    }

    cout << "Case #" << tc << ": ";
    cout << "Possible" << endl;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << '^';
        }
        cout << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}

/*
Case #1: Impossible
Case #2: Possible
.
.
.
Case #3: Possible
^^^^
^^^^
^^^^
^^^^
Case #4: Possible
.
Case #5: Possible

*/