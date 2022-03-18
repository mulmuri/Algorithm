#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define sum SUM

const int ST_MAX = 1 << 13;

// 스위치

#define endl '\n'

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
            arr[i] = arr[i*2] + arr[i*2+1];
    }
 
    // 구간 [ns, ne)인 node의 lazy 값을 propagate
    void propagate(int node, int ns, int ne){
        if(lazy[node]){
            // 리프 노드가 아님
            if(node < start){
                lazy[node*2] ^= 1;
                lazy[node*2+1] ^= 1;
 
                // 왼쪽 자식과 오른쪽 자식의 결과로 자신의 결과 갱신
                int temp = 0;
                // 만약 왼쪽 자식 전체가 반전될 것이라면, 실질적인 값은 구간 크기 - 현재 값
                if(lazy[node*2]) temp += (ne-ns)/2 - arr[node*2];
                // 아니면 그냥 현재 값
                else temp += arr[node*2];
                // 오른쪽 자식도 마찬가지
                if(lazy[node*2+1]) temp += (ne-ns)/2 - arr[node*2+1];
                else temp += arr[node*2+1];
 
                arr[node] = temp;
            }
            // 리프 노드
            else arr[node] ^= 1;
 
            lazy[node] = false;
        }
    }
 
    // 구간 [s, e)에 k를 더하라
    void add(int s, int e){ add(s, e+1, 1, 0, start); }
    void add(int s, int e, int node, int ns, int ne){
        propagate(node, ns, ne);
        if(e <= ns || ne <= s) return;
        if(s <= ns && ne <= e){
            // lazy 값을 반전시킴
            lazy[node] ^= 1;
            propagate(node, ns, ne);
            return;
        }
        int mid = (ns+ne)/2;
        add(s, e, node*2, ns, mid);
        add(s, e, node*2+1, mid, ne);
        arr[node] = arr[node*2] + arr[node*2+1];
    }
 
    // 구간 [s, e)의 합을 구하라
    long long sum(int s, int e){ return sum(s, e+1, 1, 0, start); }
    long long sum(int s, int e, int node, int ns, int ne){
        // 일단 propagate
        propagate(node, ns, ne);
 
        if(e <= ns || ne <= s) return 0;
        if(s <= ns && ne <= e) return arr[node];
        int mid = (ns+ne)/2;
        return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
    }
};



int n,q;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    SegTree sum_st;

    while (q--) {
        int a,b,c;
        cin >> a >> b >> c;

        if (a == 1) {
            cout << sum_st.sum(b,c) << endl;
        } else {
            sum_st.add(b, c);
        }
    }

}
