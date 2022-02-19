#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"




const int MAX = 2e5 + 4;
const int MOD = 1e9 + 7;
const int SMAX = (1 << 19);

int n, qq, C, l[MAX], r[MAX];
vector<int> seg[SMAX], g[MAX];

int counter = 0;
void makelr(int u, int p) {
	l[u] = counter++;
	for (int v : g[u]) if (v != p) makelr(v, u);
	r[u] = counter-1;
}

void construct() {
	for (int i = SMAX / 2 - 1; i >= 1; i--) {
		seg[i] = seg[i * 2 + 1];
		seg[i].insert(seg[i].end(), seg[i * 2].begin(), seg[i * 2].end());
		sort(seg[i].begin(), seg[i].end());
	}
}

int val(int s, int e, int k, int i = 1, int ns = 0, int ne = SMAX / 2 - 1) {
	if (e < ns || ne < s) return 0;
	if (s <= ns && ne <= e) 
        return seg[i][seg[i].size()-k];
		//return upper_bound(seg[i].begin(), seg[i].end(), k) - seg[i].begin();
	int md = (ns + ne) / 2;
	return val(s, e, k, i * 2, ns, md) + val(s, e, k, i * 2 + 1, md + 1, ne);
}

int main() {
	fastio; cin >> n >> qq;
	vector<int> inp(n+1);
	for (int i = 1; i <= n; i++) cin >> inp[i];
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	makelr(1, 0);
	for (int i = 1; i <= n; i++) 
		seg[l[i] + SMAX / 2].push_back(inp[i]);
	
	construct();

	for (int i = 0; i < qq; i++) {
        int v,k;
		cin >> v >> k;
        cout << val(l[v], r[v], k) << endl;
	}
}
