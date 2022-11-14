#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1001;
typedef long long ll;



int b,q;

ll high[SIZE];
int lenh[SIZE];
ll low[SIZE];
int lenl[SIZE];



int main() {
    cin >> b;

    for (int i=0; i<b; i++) {
        string s; cin >> s;
        //reverse(s.begin(), s.end());

        int v = 0;
        for (char c: s) {
            v <<= 1;
            if (c == '1') v += 1;
        }
        high[i] = v;
        lenh[i] = s.size();
    }

    for (int i=0; i<b; i++) {
        string s; cin >> s;
        //reverse(s.begin(), s.end());

        int v = 0;
        for (char c: s) {
            v <<= 1;
            if (c == '1') v += 1;
        }
        low[i] = v;
        lenl[i] = s.size();
    }

    cin >> q;

    while (q--) {
        string s; cin >> s;

        int ans = 0;

        for (int i=0; i<b; i++) {
            int v = 0;
            int l = lenh[i];
            int t = high[i];

            for (int j=0; j<s.size(); j++) {
                v <<= 1;
                v %= (1 << l);
                if (s[j] == '1') v += 1;

                if (j >= l-1 && v == t) ans++;
            }
        }

        for (int i=0; i<b; i++) {
            int v = 0;
            int l = lenl[i];
            int t = low[i];

            for (int j=0; j<s.size(); j++) {
                v <<= 1;
                v %= (1 << l);
                if (s[j] == '1') v += 1;

                if (j >= l-1 &&  v == t) ans--;
            }
        }

        if (ans > 0) cout << "HIGH " << ans << endl;
        else if (ans < 0) cout << "LOW " << -ans << endl;
        else cout << "GOOD " << endl;
    }

}