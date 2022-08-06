#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'

const int SIZE = 1025;



class Seg2D{
public:
    int n;
    vector<vector<int>> a;
    Seg2D(int n) : n(n), a(2*n,vector<int>(2*n)){}

    void init(vector<vector<int>>& val){
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                a[i+n][j+n] = val[i][j];
        }

        for (int i = n; i < 2*n; i++) {
            for (int j = n-1; j > 0; j--) a[i][j] = merge(a[i][j<<1], a[i][j<<1|1]);
        }

        for (int i = n-1; i > 0; i--) {
            for (int j = 1; j < 2*n; j++) {
                a[i][j] = merge(a[i<<1][j], a[i<<1|1][j]);
            }
        }
    }

    void upd(int x, int y, int val) {
        a[x+n][y+n] = val;
        for (int i = y+n; i > 1; i >>= 1)  a[x+n][i>>1] = merge(a[x+n][i], a[x+n][i^1]);
        for (x = x+n; x > 1; x >>= 1){
            for (int i = y+n; i >= 1; i >>= 1){
                a[x>>1][i] = merge(a[x][i], a[x^1][i]);
            }
        }
    }

    int query1D(int x, int y1, int y2){
        int ret = 0;
        for (y1 += n, y2 += n+1; y1 < y2; y1 >>= 1, y2 >>= 1) {
            if(y1 & 1) ret = merge(ret, a[x][y1++]);
            if(y2 & 1) ret = merge(ret, a[x][--y2]);
        }    
        return ret;
    }

    int query(int x1, int y1, int x2, int y2) {
        int ret = 0;
        for (x1 += n, x2 += n+1; x1 < x2; x1 >>= 1, x2 >>= 1) {
          if (x1&1) ret = merge(ret, query1D(x1++, y1, y2));
          if (x2&1) ret = merge(ret, query1D(--x2, y1, y2));
        }
        return ret;
    }

    int merge(int l, int r) {
        return l + r;
    }
};


int n,m;
vector<vector<int> > arr(n,vector<int>(n));


int main() {
    cin >> n >> m;
    Seg2D seg(n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> arr[i][j];
    seg.init(arr);

    while (m--) {
        int w;
        cin >> w;
        if (w == 0){
            int x,y,c;
            cin >> x >> y >> c;
            x--; y--;
            seg.upd(x,y,c);
        }
        else {
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            cout << seg.query(x1,y1,x2,y2) << endl;
        }
    }


}