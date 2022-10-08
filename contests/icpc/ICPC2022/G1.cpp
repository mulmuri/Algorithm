#include <bits/stdc++.h>
using namespace std;

int dp[30][105][105][105];
bool used[30][105][105][105];

const int F = 1;
const int S = 0;
const int INF = 500;

int solve(int t, int a, int b, int c)
{
    int p = 0;
    if (used[t][a][b][c])
        return dp[t][a][b][c];

    if (t % 2 == F)
    {

        dp[t][a][b][c] = -INF;

        p = min(t, a);
        if (p != 0)
            dp[t][a][b][c] = max(dp[t][a][b][c], solve(t + 1, a - p, b, c) + p);

        p = min(t, b);
        if (p != 0)
            dp[t][a][b][c] = max(dp[t][a][b][c], solve(t + 1, a, b - p, c) + p);

        p = min(t, c);
        if (p != 0)
            dp[t][a][b][c] = max(dp[t][a][b][c], solve(t + 1, a, b, c - p) + p);

        used[t][a][b][c] = true;
        return dp[t][a][b][c];
    }

    if (t % 2 == S)
    {
        dp[t][a][b][c] = INF;

        p = min(t, a);
        if (p != 0)
            dp[t][a][b][c] = min(dp[t][a][b][c], solve(t + 1, a - p, b, c) - p);

        p = min(t, b);
        if (p != 0)
            dp[t][a][b][c] = min(dp[t][a][b][c], solve(t + 1, a, b - p, c) - p);

        p = min(t, c);
        if (p != 0)
            dp[t][a][b][c] = min(dp[t][a][b][c], solve(t + 1, a, b, c - p) - p);

        used[t][a][b][c] = true;
        return dp[t][a][b][c];
    }
}

int main()
{

    int a, b, c;

    cin >> a >> b >> c;
    for (int i = 0; i < 30; ++i)
    {
        dp[i][0][0][0] = 0;
        used[i][0][0][0] = true;
    }

    int ret = solve(1, a, b, c);
    if (ret > 0)
        cout << "F" << endl;
    else if (ret < 0)
        cout << "S" << endl;
    else
        cout << "D" << endl;
}