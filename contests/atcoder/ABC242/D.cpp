#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define MOD 998232453
#define INF 1e9
#define SIZE 200001



string s;
int q;

int main() {
    fastio;

    cin >> s >> q;

    while (q--) {
        long long t,k;
        cin >> t >> k;

        long long it = t;
        long long ik = k-1;


        long long cnt = 0;
        while (it && ik) {
            it--;
            cnt += (ik % 2);
            ik /= 2;
        }

        if (it == 0) {
            cout << (char) ((s[ik]-'A' + cnt + t)%3 + 'A') << endl;
        } else {
            cout << (char) ((s[0]-'A' + cnt + t)%3 + 'A') << endl;
        }
    }
}