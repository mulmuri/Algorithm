#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998244353;
const int INF = 1e18;
const int SIZE = 300001;


int n,q;
int arr[SIZE];

priority_queue<int, vector<int>, greater<int> > pq[SIZE];

set<int> st[SIZE];

void print_set(set<int> st) {
    vector<int> v;
    for (auto it=st.begin(); it!=st.end(); it++) v.push_back(*it);
    sort(v.begin(), v.end());

    for (auto e: v) cout << e <<' '; cout << endl;
}

void print_queue(priority_queue<int, vector<int>, greater<int> > pq) {

    while (!pq.empty()) {
        int top_element = pq.top();
        cout << top_element <<' ';
        pq.pop();
    }
    cout << endl;
}




int32_t main() {
    fastio;

    cin >> n >> q;

    while (q--) {
        int x,a,b;
        cin >> x;

        switch (x) {
            case 1:
                cin >> a >> b;
                pq[b].push(a); // box
                st[a].insert(b); // card
                break;
            case 2:
                cin >> a;
                print_queue(pq[a]);
                break;
            case 3:
                cin >> b;
                print_set(st[b]);
                break;
        }
    }

}