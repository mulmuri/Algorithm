#include <iostream>
#include <string>
using namespace std;


int ans;

void solve(int tc) {
    string s,t;
    int n;

    cin >> s;
    n = s.size();
    
    s += ' ';

    int cnt = 0;
    int last = s[0];

    for (int i=0; i<n; i++) {
        cnt++;
        if (s[i] != s[i+1]) {
            if (s[i] < s[i+1]) {
                for (int j=0; j<cnt*2; j++) t += s[i];
            } else {
                for (int j=0; j<cnt; j++) t += s[i];
            }
            cnt = 0;
        }
    }

    cout << "Case #"<< tc << ": " << t << endl;
}

int main() {
    int t; cin >> t;
    for (int i=1; i<=t; i++) solve(i);
}