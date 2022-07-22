#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    vector<P> L(n);
    for (int i = 0; i < n; ++i){
        L[i].first = A[i];
        L[i].second = i;
    }

    sort(L.begin(), L.end());
    long long ANS = 0;

    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i){
        int p = L[i].second;
        
        int m1 = max(p - left, 0);
        int m2 = max(right - p, 0);

        ANS += min(m1, m2);
        if (m1 <= m2) left++;
        else right--;
    }

    cout << ANS << endl;
}