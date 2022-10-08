#include <bits/stdc++.h>
using namespace std;

const int SIZE = 101;
const int STEP = 30;



int a,b,c;

int dp[STEP][SIZE][SIZE][SIZE];
int f[STEP][SIZE][SIZE][SIZE];


int main() {
    cin >> a >> b >> c;

    f[0][0][0][0] = 1;

    for (int t=0; t<STEP; t++) {
        for (int i=0; i<=a; i++) {
            for (int j=0; j<=b; j++) {
                for (int k=0; k<=c; k++) {
                    if (f[t][i][j][k] == 0) continue;

                    if (a != i) {
                        if (t%2 == 0) dp[t+1][min(i+t,a)][j][k] = max(dp[t+1][min(i+t,a)][j][k], dp[t][i][j][k] + min(t, a-i));
                        else dp[t+1][min(i+t,a)][j][k] = min(dp[t+1][min(i+t,a)][j][k], dp[t][i][j][k] - min(t, a-i));
                        f[t+1][min(i+t,a)][j][k] = 1;
                    }

                    if (b != j) {
                        if (t%2 == 0) dp[t+1][i][min(j+t,b)][k] = max(dp[t+1][i][min(j+t,b)][k], dp[t][i][j][k] + min(t, b-j));
                        else dp[t+1][i][min(j+t,b)][k] = min(dp[t+1][i][min(j+t,b)][k], dp[t][i][j][k] - min(t, b-j));
                        f[t+1][i][min(j+t,b)][k] = 1;
                    }

                    if (c != k) {
                        if (t%2 == 0) dp[t+1][i][j][min(k+t,c)] = max(dp[t+1][i][j][min(k+t,c)], dp[t][i][j][k] + min(t, c-k));
                        else dp[t+1][i][j][min(k+t,c)] = min(dp[t+1][i][j][min(k+t,c)], dp[t][i][j][k] - min(t, c-k));
                        f[t+1][i][j][min(k+t,c)] = 1;
                    }
                }
            }
        }
    }

    

    



}