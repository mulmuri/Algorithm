#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 1000001
typedef long long ll;


struct item {
    int type;
    int num;
};


int original[SIZE];
int nodes[SIZE*4];
int n,m,k,q;


int query(int index, int nodeStart, int nodeEnd, int reqIndex) {
    int nodeMid = (nodeStart + nodeEnd) / 2;
    if (nodeStart == nodeEnd) return nodes[index];
    else {
        if (reqIndex <= nodeMid) return query(index * 2, nodeStart, nodeMid, reqIndex);
        else return query(index * 2 + 1, nodeMid + 1, nodeEnd, reqIndex);
    }
}


void update(int index, int nodeStart, int nodeEnd, int reqStart, int reqEnd, int value) {
    int nodeMid = (nodeStart + nodeEnd) / 2;
    if (reqEnd < nodeStart || nodeEnd < reqStart) return; // 쿼리 무시
    if (reqStart <= nodeStart && nodeEnd <= reqEnd) nodes[index] = value;
    update(index * 2, nodeStart, nodeMid, reqStart, reqEnd, value); // left
    update(index * 2 + 1, nodeMid + 1, nodeEnd, reqStart, reqEnd, value); // right
}


item incinerator[SIZE];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> q;

    for (int i=1; i<=n; i++) {
        int type; cin >> type;
        incinerator[i] = {type, 1};
    }

    for (int i=1; i<=min(n,m); i++) {
        update(1, 0, m, i, i, incinerator[i].type);
    }
    int lidx = min(n, m)+1;
    int ridx = m;



    while (q--) {
        int o, a, b;
        cin >> o;
        if (o == 1) {
            cin >> a >> b;

        } else if (o == 2) {
            cin >> a;
            cout << query(1, 0, m, a) << endl;
        } else if (o == 3) {
            cin >> a >> b;
            incinerator[++ridx] = {a,b};
        } else if (o == 4) {
            cin >> a;
            while (a) {
                if (incinerator[lidx].num > a) {
                    incinerator[lidx].num -= a;
                    a = 0;
                } else {
                    a -= incinerator[lidx].num;
                    lidx++; 
                }
            }
        }
    }

    


}


