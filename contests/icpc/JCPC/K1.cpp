#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define LEFT_MAX 5001
#define RIGHT_MAX 5001

std::vector<int> connected[LEFT_MAX];
bool visited[LEFT_MAX];
int matching[RIGHT_MAX];

bool findValidPair(int start) {
    if (visited[start]) {
        return false;
    }
    visited[start] = true;

    for (int opposite : connected[start]) {
        if (matching[opposite] == 0 || findValidPair(matching[opposite])) {
            matching[opposite] = start;
            return true;
        }
    }
    return false;
}

int bipartite(int N) {
    int result = 0;
    
    for (int i = 1; i <= N; ++i) {
        std::fill(visited, visited + N+1, false);
        result += (findValidPair(i) ? 1 : 0);
    }
    return result;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    std::cin >> N;

    std::vector<int> p(N+1), f(N+1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> p[i];
    }
    for (int i = 1; i <= N; ++i) {
        std::cin >> f[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (p[i] < f[j]) {
                connected[i].push_back(j);
            }
        }
        std::sort(connected[i].begin(), connected[i].end(), [&](int v1, int v2) { return f[v1] < f[v2]; });
    }

    int tricks = bipartite(N);
    std::vector<int> answer(N+1, -1), unused;
    for (int i = 1; i <= N; ++i) {
        if (matching[i]) {
            answer[matching[i]] = f[i];
        } else {
            unused.push_back(f[i]);
        }
    }

    std::sort(unused.begin(), unused.end());
    for (int i = 1; i <= N; ++i) {
        if (answer[i] == -1) {
            answer[i] = unused.back();
            unused.pop_back();
        }
    }
    for (int i = 1; i <= N; ++i) {
        std::cout << answer[i] << " ";
    }

    return 0;
}