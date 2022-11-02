#include <bits/stdc++.h>
using namespace std;



int t,z;
int atk[5][102];
int pfatk[5][102];
int atklen[5];
int cost[3][52];
int skill[3][5][52];
int prolen[3];
int lv[5];



int main() {
    cin >> t >> z;

    for (int u=0; u<5; u++) {
        int l; cin >> l; atklen[u] = l;
        for (int i=1; i<=l; i++) {
            cin >> atk[u][i];
            pfatk[u][i] = pfatk[u][i-1] + atk[u][i];
        }
    }

    for (int u=0; u<3; u++) {
        int m; cin >> m; prolen[u] = m;
        for (int i=0; i<m; i++) cin >> cost[u][i];
        for (int i=0; i<m; i++) for (int v=0; v<5; v++) cin >> skill[u][v][i];
    }

    int ans = 0;

    for (int i=0; i<=prolen[0]; i++) for (int j=0; j<=prolen[1]; j++) for (int k=0; k<=prolen[2]; k++) {
        int newT = t - cost[0][i] - cost[1][j] - cost[2][k];
        if (newT < 0) continue;

        int atkv = 0;
        for (int u=0; u<5; u++) {
            lv[u] = skill[0][u][i] + skill[1][u][j] + skill[2][u][k];
        }

        if (newT >= z) {
            for (int u=0; u<5; u++) for (int v=0; v<5; v++) {
                if (lv[u] == 0) continue;
                lv[u]--; lv[v]++;

                int sum = 0;
                for (int w=0; w<5; w++) sum += ((lv[w] > atklen[w]) ? atk[w][atklen[w]] : atk[w][lv[w]]);
                ans = max(ans, sum);

                lv[u]++; lv[v]--;
            }
        } else {
            int sum = 0;
            for (int w=0; w<5; w++) sum += ((lv[w] > atklen[w]) ? atk[w][atklen[w]] : atk[w][lv[w]]);
            ans = max(ans, sum);
        }
    }

    cout << ans;
}