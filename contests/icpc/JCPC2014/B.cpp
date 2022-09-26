#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;

    vector<int> V(N);
    vector<vector<P>> L(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];
    
    sort(V.begin(), V.end());

    for (int i = 0; i < N; ++i){
        for (int j = i - 1; j >= 0; --j){
            int d = V[i] - V[j];
            auto it = lower_bound(L[j].begin(), L[j].end(), make_pair(d, 0));
            if (it == L[j].end() || it -> first != d)
                L[i].emplace_back(d, 2);
            else L[i].emplace_back(d, it->second + 1);
        }
    }

    int ANS = 0;
    for (int i = 0; i < N; ++i){
        for (auto p : L[i])
            ANS = max(ANS, p.second);
    }

    cout << ANS << endl;
}