#include <bits/stdc++.h>
using namespace std;



string s;
int n;

int win[200];
int now[200];

vector<char> stk;
vector<char> alp;

int main() {
    cin >> s;
    for (char c: s) if ('a' <= c && c <= 'z') alp.push_back(c);
    n = alp.size();

    for (int i=0; i<n; i++) {
        char c; int m;
        cin >> c >> m;
        win[c] = m;
    }

    for (char c: s) {
        if ('a' <= c && c <= 'z') stk.push_back(c);
        if (c == ']') {
            int p = stk.back(); stk.pop_back();
            int q = stk.back(); stk.pop_back();

            if (win[p] == now[p] && win[q] > now[q]) {
                now[q]++;
                stk.push_back(q);
            } else if (win[p] > now[p] && win[q] == now[q]) {
                now[p]++;
                stk.push_back(p);
            } else {
                cout << "No";
                return 0;
            }
        }
    }

    for (char c: s) if (win[c] != now[c]) {
        cout << "No";
        return 0;
    }

    cout << "Yes";
}