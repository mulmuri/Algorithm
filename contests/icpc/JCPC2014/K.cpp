#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> p(n), f(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i];
    }

    auto getMaxTricks = [&]() -> std::vector<int> {
        std::vector<std::pair<int, int>> pSorted(n);
        for (int i = 0; i < n; ++i) {
            pSorted[i] = { p[i], i };
        }
        std::sort(pSorted.begin(), pSorted.end());
        std::multiset<int> has(f.begin(), f.end());
        std::vector<int> answer(n);

        for (int i = 0; i < n; ++i) {
            auto found = has.upper_bound(pSorted[i].first);
            if (found == has.end()) {
                answer[pSorted[i].second] = *has.begin();
                has.erase(has.begin());
            } else {
                answer[pSorted[i].second] = *found;
                has.erase(found);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ti = std :: min(i, j);
                int tj = std :: max(i, j);
                if (answer[ti] < answer[tj]) {
                    int prev = (p[ti] < answer[ti] ? 1 : 0) + (p[tj] < answer[tj] ? 1 : 0);
                    int next = (p[ti] < answer[tj] ? 1 : 0) + (p[tj] < answer[ti] ? 1 : 0);
                    if (prev == next) {
                        std::swap(answer[ti], answer[tj]);
                    }
                }
            }
        }

        return answer;
    };
    
    for (int v : getMaxTricks()) {
        std::cout << v << " ";
    }

    return 0;
}