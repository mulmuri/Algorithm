#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'
#define int long long

const int MOD = 998232453;
const int INF = 1e18;
const int SIZE = 200001;


int n;
string s;
stack<int> stk1;
stack<int> stk2;
vector<int> arr;

int32_t main() {
    cin >> s;
    for (char e: s) {
        if (e == '?') arr.push_back(1);
        else if (e == ':') arr.push_back(-1);
    }

    for (auto i: arr) {
        
    }



    fastio;
}