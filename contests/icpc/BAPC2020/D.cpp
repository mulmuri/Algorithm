#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int c; cin >> c; sum += c;
    }
    if (sum%3 == 0) cout << "yes";
    else cout << "no";
}