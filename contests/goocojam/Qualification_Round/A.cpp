#include <iostream>
using namespace std;


void solve(int tc) {
    int r,c; cin >> r >> c;

    cout << "Case #"<< tc << ":\n";

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << ((i == 0 && j == 0) ? ".." : "+-");
        }
        cout << "+\n";

        for (int j=0; j<c; j++) {
            cout << ((i == 0 && j == 0) ? ".." : "|.");
        }
        cout << "|\n";
    }

    for (int j=0; j<c; j++) {
        cout << "+-";
    }
    cout << "+\n";
}

int main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}