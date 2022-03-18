// 괄호 문자열과 쿼리

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

#define SIZE 100001
#define INF 1e9


const int ST_MAX = (1 << 22);

// 세그먼트 트리 구조체
struct SegTree{
    int start;
    long long arr[ST_MAX], lazy[ST_MAX];
 
    // 생성자
    SegTree(){
        start = ST_MAX/2;
        fill(arr, arr+ST_MAX, 0);
        fill(lazy, lazy+ST_MAX, 0);
    }
 
    // 리프 노드들의 값을 먼저 입력한 후 전체 세그먼트 트리 구축
    void construct(){
        for(int i=start-1; i>0; i--)
            arr[i] = min(arr[i*2], arr[i*2+1]);
    }
 
    // 구간 [ns, ne)인 node의 lazy 값을 propagate
    void propagate(int node, int ns, int ne){
        // lazy 값이 존재하면 실행
        if(lazy[node] != 0){
            // 리프 노드가 아니면 자식들에게 lazy 미룸
            if(node < start){
                lazy[node*2] = lazy[node];
                lazy[node*2+1] = lazy[node];
            }
            // 자신에 해당하는 만큼의 값을 더함
            arr[node] += lazy[node];
            lazy[node] = 0;
        }
    }
 
    // 구간 [s, e)에 k를 더하라
    void update(int s, int e, int k){ update(s, e+1, k, 1, 0, start); }
    void update(int s, int e, int k, int node, int ns, int ne){
        // 일단 propagate
        propagate(node, ns, ne);
 
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            // 이 노드가 구간에 완전히 포함되면 lazy 부여 후 propagate
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        update(s, e, k, node*2, ns, mid);
        update(s, e, k, node*2+1, mid, ne);
        // 마지막에 자식들의 값을 사용해 다시 자신의 값 갱신
        arr[node] = min(arr[node*2], arr[node*2+1]);
    }
 
    // 구간 [s, e)의 합을 구하라
    long long query(int s, int e){ return query(s, e+1, 1, 0, start); }
    long long query(int s, int e, int node, int ns, int ne){
        // 일단 propagate
        propagate(node, ns, ne);
 
        if(e <= ns || ne <= s) return INF;
        if(s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return min(query(s, e, node*2, ns, mid), query(s, e, node*2+1, mid, ne));
    }
};



string s;
int n,m;
int arr[SIZE];

int ans = 0;


int main(){
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    for (int i=1; i<=n; i++) arr[i] = arr[i-1] + ((s[i] == '(') ? 1 : -1);

    SegTree min_st;
    for (int i=1; i<=n; i++) min_st.arr[min_st.start + i] = arr[i];
    min_st.construct();


    if (min_st.query(1, n) >= 0 && min_st.query(n,n) == 0) ans++;  
    while (m--) {
        int i; cin >> i;

        if (s[i] == ')') {
            s[i] = '(';
            min_st.update(i, n, 2);
        } else {
            s[i] = ')';
            min_st.update(i, n, -2);
        }

        if (min_st.query(1, n) >= 0 && min_st.query(n,n) == 0) ans++;  

        for (int i=1; i<=n; i++) cout << min_st.query(i, i) <<' ';
        cout << endl;
    }

    cout << ans;
}
