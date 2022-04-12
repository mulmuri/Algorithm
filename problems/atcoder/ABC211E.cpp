#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
using namespace std;
#define int long long
typedef long long ll;
#define INF 1987654321
#define SIZE 8

int n,k;
int board[SIZE][SIZE];
int ans = 0;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

bool isOk(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool isConnected() {
    int vis[SIZE][SIZE];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) vis[i][j] = 0;

    int c = 0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (board[i][j] != '*' || vis[i][j] == 1) continue;
        c++;

        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int k=0; k<4; k++) {
                int ny = y+dy[k];
                int nx = x+dx[k];
                if (!isOk(ny,nx)) continue;
                if (board[ny][nx] != '*' || vis[ny][nx] == 1) continue;
                vis[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }

    if (c == 1) return 1;
    else return 0;
}

bool canbeConnected() {
    int vis[SIZE][SIZE];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) vis[i][j] = 0;

    int c = 0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        if (board[i][j] != '*' || vis[i][j] == 1) continue;
        c++;

        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int k=0; k<4; k++) {
                int ny = y+dy[k];
                int nx = x+dx[k];
                if (!isOk(ny,nx)) continue;
                if (board[ny][nx] == '#' || vis[ny][nx] == 1) continue;
                vis[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }

    if (c <= 1) return 1;
    else return 0;
}

void DFS(int y, int x, int count) {

    if (count == k) {
        if (isConnected()) ans++;
        return;
    }

    if (y == n && x == n)
        return;

    if (!canbeConnected())
        return;

    int ny, nx;

    if (board[y][x] == '#') {
        if (x == n-1) {
            if (y == n-1) {
                ny = n;
                nx = n;
            }
            else {
                ny = y+1; nx = 0;
            }
        } else {
            ny = y; nx = x+1;
        }
        DFS(ny,nx,count);
        return;
    }

    board[y][x] = '#';
    if (x == n-1) {
        if (y == n-1) {
            ny = n;
            nx = n;
        }
        else {
            ny = y+1; nx = 0;
        }
    } else {
        ny = y; nx = x+1;
    }
    DFS(ny,nx,count);

    board[y][x] = '*';
    if (x == n-1) {
        if (y == n-1) {
            ny = n;
            nx = n;
        }
        else {
            ny = y+1; nx = 0;
        }
    } else {
        ny = y; nx = x+1;
    }
    DFS(ny,nx,count+1);

    board[y][x] = '.';
}

int32_t main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<n; j++) board[i][j] = s[j];
    }

    DFS(0,0,0);
    cout << ans;
}
