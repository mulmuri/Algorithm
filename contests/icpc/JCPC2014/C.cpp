#include <iostream>
#include <vector>
#include <algorithm>

class DisjointSet {
private:
    std::vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int p) {
        if (parent[p] == p) {
            return p;
        }
        return parent[p] = find(parent[p]);
    }

    void merge(int p, int q) {
        int pPar = find(p);
        int qPar = find(q);
        if (pPar != qPar) {
            parent[pPar] = qPar;
        }
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int r, s, p;
    std::cin >> r >> s >> p;

    DisjointSet dsu(2*r*s+10);
    std::vector<bool> occupied(2*r*s+10, false);
    std::vector<int> pasPerRow[r];

    for (int i = 0; i < p; ++i) {
        int pr, pc;
        std::cin >> pr >> pc;
        pasPerRow[r-pr].push_back(pc <= s ? (s-pc) : (pc-s-1));
    }

    for (int i = r-1; i >= 0; --i) {
        std::sort(pasPerRow[i].begin(), pasPerRow[i].end());
        for (int c : pasPerRow[i]) {
            if (occupied[c+i+1]) {
                int blank = dsu.find(c+i+1);
                occupied[blank] = true;
                dsu.merge(blank, blank+1);
            } else {
                occupied[c+i+1] = true;
                dsu.merge(c+i+1, c+i+2);
            }
        }
    }

    for (int i = occupied.size()-1; i >= 0; --i) {
        if (occupied[i]) {
            std::cout << i+1;
            break;
        }
    }

    return 0;
}