#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 100001

typedef long long ll;

const ll INF = 2e18;



struct Line {
    ll a, b;
    Line(): a(0), b(-INF) {}
    Line(ll a1, ll b1): a(a1), b(b1) {}
    ll f(ll x) {
        return a * x + b;
    }
};

struct Node {
    int l, r;
    ll s, e;
    Line line;
    Node(int l1, int r1, ll s1, ll e1, Line line1) : l(l1), r(r1), s(s1), e(e1), line(line1) {}
};

struct LiChaoTree {
    vector<Node> nodes;

    LiChaoTree() { nodes.emplace_back(-1, -1, -INF, INF, Line()); }
    LiChaoTree(ll s, ll e) { nodes.emplace_back(-1, -1, s, e, Line()); }

    void update(Line newLine) { update(0, newLine); }
    void update(int i, Line newLine) {
        ll s, e, mid;
        s = nodes[i].s; e = nodes[i].e;
        mid = (s + e) / 2;

        Line low, high;
        if (nodes[i].line.f(s) > newLine.f(s)) {
            low = newLine;
            high = nodes[i].line;
        } else {
            low = nodes[i].line;
            high = newLine;
        }

        if (low.f(e) < high.f(e)) {
            nodes[i].line = high;
        } else if (low.f(mid) < high.f(mid)) {
            nodes[i].line = high;
            if (nodes[i].r == -1) {
                nodes[i].r = nodes.size();
                nodes.emplace_back(-1, -1, mid + 1, e, Line());
            }
            update(nodes[i].r, low);
        } else {
            nodes[i].line = low;
            if (nodes[i].l == -1) {
                nodes[i].l = nodes.size();
                nodes.emplace_back(-1, -1, s, mid, Line());
            }
            update(nodes[i].l, high);
        }
    }

    ll query(ll x) { return query(0, x); }
    ll query(int i, ll x) {
        if (i == -1) return -INF;
        ll mid = (nodes[i].s + nodes[i].e) / 2;
        ll ret = nodes[i].line.f(x);
        if (x <= mid) return max(ret, query(nodes[i].l, x));
        else return max(ret, query(nodes[i].r, x));
    }
};



int n;

ll dp[SIZE];
pair<ll, ll> area[SIZE];


int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> area[i].first >> area[i].second;
    sort(area, area+n, greater<>());
    for (int i=0; i<n; i++) area[i] = {area[i].second, area[i].first};

    //for (int i=0; i<n; i++) {
    //    cout << area[i].first <<' '<< area[i].second << endl;
    //}

    LiChaoTree cht;
    cht.update(Line(area[0].second, 0));

    for (int i=0; i<n; i++) {
        ll ret = cht.query(area[i].first); // a(i)
        dp[i] = ret; // dp(i) = a(i) * b(j) + c(j) + d(i)
        cht.update(Line(area[i+1].second, dp[i])); // b(i), c(i)
    };

    cout << dp[n-1];
}