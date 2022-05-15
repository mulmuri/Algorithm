#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 300001;


int n;
string s;

int32_t main() {
    fastio;
    
    cin >> n >> s;

    vector<int> arc;
    int point = 0;

    int state = 0;
    int cnta = 0, cntc = 0;
    for (int i=0; i<n; i++) {
        if (state == 0) {
            if (s[i] == 'A') {
                cnta++;
            } else if (s[i] == 'R') {
                if (cnta > 0) state = 1;
                else cnta = 0;
            } else if (s[i] == 'C') {
                cnta = 0;
            }
        } else if (state == 1) {
            if (s[i] == 'A') {
                if (cntc > 0) {
                    if (min(cnta, cntc) == 1) point++;
                    else arc.push_back(min(cnta, cntc));
                }
                state = 0;
                cnta = 1, cntc = 0;
            } else if (s[i] == 'R') {
                if (cntc > 0) {
                    if (min(cnta, cntc) == 1) point++;
                    else arc.push_back(min(cnta, cntc));
                }
                state = 0;
                cnta = 0, cntc = 0;
            } else if (s[i] == 'C') {
                cntc++;
            }
        }

        if (i == n-1 && state == 1 && cntc > 0) {
            if (min(cnta, cntc) == 1) point++;
            else arc.push_back(min(cnta, cntc));
        }
    }

    int ans = point;
    sort(arc.begin(), arc.end());
    //cout << arc.size() <<' '<< point << endl;

    for (int i=0; i<arc.size(); i++) {
        if (arc[i]-2 > point) {
            ans += point;
            arc[i] -= point;
            point = 0;
            
            ans += (arc.size() - i) * 2;
            break;
        } else {
            point -= (arc[i]-2);
            ans += arc[i];
        }
    }
    
    cout << ans;
}